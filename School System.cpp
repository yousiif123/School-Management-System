#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>

using namespace std;
class student
{
	private:
		char id[15];
		char name[20];
		char gender;
		float quiz1;
		float quiz2;
		float quizscore; // 2 quizzes score
		float mid1;
		float mid2;
		float midscore; // 2 mids score
		float finalscore;
	public:
		student()
		{
			
		}
		student(char a[15],char b[20],char c,float d,float e,float f,float g,float h,float i,float j)
		{
			strcpy(id,a);
			strcpy(name,b);
			gender=c;
			quiz1=d;
			quiz2=e;
			quizscore=f;
			mid1=g;
			mid2=h;
			midscore=i;
			finalscore=j;
		}
		//setting values using constructor
		char* getid()
		{
			return id;
		}
		char* getname()
		{
			return name;
		}
		char getgender()
		{
			return gender;
		}
		float getquiz1()
		{
			return quiz1;
		}
		float getquiz2()
		{
			return quiz2;
		}
		float getquizscore()
		{
			return quizscore;
		}
		float getmid1()
		{
			return mid1;
		}
		float getmid2()
		{
			return mid2;
		}
		float getmidscore()
		{
			return midscore;
		}
		float getfinalscore()
		{
			return finalscore;
		}
		//Functions
		//To get data from user
		void getdata()
		{
			system("CLS");
			cout<<"ENTER ID OF STUDENT: ";
			cin>>id;
			cout<<"ENTER NAME OF STUDENT: ";
			cin>>name;
			cout<<"ENTER GENDER OF STUDENT M or F : ";
			cin>>gender;
			cout<<"ENTER QUIZ 1 SCORE: ";
			cin>>quiz1;
			cout<<"ENTER QUIZ 2 SCORE: ";
			cin>>quiz2;
			cout<<"ENTER MID 1 SCORE: ";
			cin>>mid1;
			cout<<"ENTER MID 2 SCORE: ";
			cin>>mid2;
			cout<<"ENTER FINAL SCORE: ";
			cin>>finalscore;
			
			//Formula
			quizscore=quiz1+quiz2;
			midscore=mid1+mid2;
			student(id,name,gender,quiz1,quiz2,quizscore,mid1,mid2,midscore,finalscore);
			store();
			
		//To update previous Records	
		}
		void modify()
		{
			cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"                                **ENTER NEW DATA** "<<endl;
			cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"ENTER ID OF STUDENT: ";
			cin>>id;
			cout<<"ENTER NAME OF STUDENT: ";
			cin>>name;
			cout<<"ENTER GENDER OF STUDENT M or F : ";
			cin>>gender;
			cout<<"ENTER QUIZ 1 SCORE: ";
			cin>>quiz1;
			cout<<"ENTER QUIZ 2 SCORE: ";
			cin>>quiz2;
			cout<<"ENTER MID 1 SCORE: ";
			cin>>mid1;
			cout<<"ENTER MID 2 SCORE: ";
			cin>>mid2;
			cout<<"ENTER FINAL SCORE: ";
			cin>>finalscore;
			
			//Formula
			quizscore=quiz1+quiz2;
			midscore=mid1+mid2;
		}
		//To print Data
		void print()
		{
			//system("CLS");
			cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"ID: "<<id<<endl;
			cout<<"NAME: "<<name<<endl;
			cout<<"GENDER "<<gender<<endl;
			cout<<"QUIZ 1 SCORE: "<<quiz1<<endl;
			cout<<"QUIZ 2 SCORE: "<<quiz2<<endl;
			cout<<"TOTAL QUIZ SCORE: "<<quizscore<<endl;
			cout<<"MID1 SCORE: "<<mid1<<endl;
			cout<<"MID2 SCORE: "<<mid2<<endl;
			cout<<"TOTAL MID TERM SCORE: "<<midscore<<endl;
			cout<<"FINAL SCORE: "<<finalscore<<endl;
			cout<<"--------------------------------------------------------------------------------------------------------"<<endl;		
		}
		
		//Filing
		//To store information
		store()
		{
			ofstream o;
			o.open("School.txt",ios::app);
			if(o.is_open())
			{
				o.write((char*)this,sizeof(*this));	
				o.close();
				cout<<"INFORMATION IS STORED...."<<endl<<"THANKYOU..."<<endl;
				
			}
			else
			{
				cout<<"FILE NOT FOUND..."<<endl;
			}		
		}
		//To read file From Data
		read()
		{
			ifstream i;
			i.open("School.txt",ios::in);
			if(i.is_open())
			{
				i.read((char*)this,sizeof(*this));
				while(!i.eof())
				{
					print();
					i.read((char*)this,sizeof(*this));
				}
			}
			else
			{
				cout<<"FILE NOT FOUND....."<<endl;
			}
			
		}
		//To Delete stored records
		deleterecord(char id[15])
		{
			ifstream i;
			ofstream o;
			i.open("School.txt",ios::in);
			if(i.is_open())
			{
				o.open("temp.txt",ios::app);
				i.read((char*)this,sizeof(*this));
				while(!i.eof())
				{
					if(strcmp(this->id,id))
					{
						
						o.write((char*)this,sizeof(*this));
						
					}
					i.read((char*)this,sizeof(*this));
				}
				i.close();
				o.close();
				remove("School.txt");
				rename("temp.txt","School.txt");
			}
			
			else
			{
				cout<<"FILE NOT FOUND...."<<endl;
			}
		}
		//To update stored Records	
		updaterecord(char i[15])
		{
			fstream f;
			f.open("School.txt",ios::in|ios::out|ios::ate);
			if(f.is_open())
			{
				//cout<<"HELLO"<<endl;
				f.seekg(0);
				f.read((char*)this,sizeof(*this));
				while(!f.eof())
				{
					if(!strcmp(this->id,i))
					{
						modify();
						f.seekp(f.tellp()-sizeof(*this ));
						f.write((char*)this,sizeof(*this));
					}
					f.read((char*)this,sizeof(*this));
				}
			}
		}
		//To Search Data from file
		search(char a[15])
		{
				ifstream i;
				i.open("School.txt");
				if(i.is_open())
				{
					i.read((char*)this,sizeof(*this));
					while(!i.eof())
					{
						if(!strcmp(a,this->id))
						{	
							print();
						}
						i.read((char*)this,sizeof(*this));
					}
				}
		}
		//To calculate average scores
		void calculateavg()
		{
			system("CLS");
			int choice;
			float avg;
			cout<<"1) QUIZ SCORES AVERAGE."<<endl<<"2) MID TERM SCORES AVERAGE."<<endl;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;
			cout<<"ENTER YOUR CHOICE: ";
			cin>>choice;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;	
			if(choice==1)
			{
				avg=(quiz1+quiz1)/2;
				cout<<"AVERAGE IN QUIZ'S: "<<avg<<endl;
			}
			else if(choice==2)
			{
				avg=(mid1+mid2)/2;
				cout<<"AVERAGE IN MID'S: "<<avg<<endl;
			}
				
		}
		//To calculate average
		average(char b[15])
		{
			ifstream i;
			i.open("School.txt");
			if(i.is_open())
			{
				i.read((char*)this,sizeof(*this));
				while(!i.eof())
				{
					if(!strcmp(this->id,b))
					{
						calculateavg();
					}
					i.read((char*)this,sizeof(*this));
				}				
			}
		}
		//To calculate highest scores
		void score()
		{
			int choice,choice2;
			float high;
			cout<<"1) QUIZ SCORES."<<endl<<"2) MID TERM SCORES."<<endl;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;
			cout<<"ENTER YOUR CHOICE: ";
			cin>>choice;
			cout<<"---------------------------------------------------------------------------------------------------"<<endl;	
			if(choice==1)
			{
				cout<<"1) HIGHEST SCORE."<<endl<<"2) LOWEST SCORE."<<endl;
				cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				cout<<"ENTER YOUR CHOICE: ";
				cin>>choice2;
				cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				if(choice2==1)
				{
					if(quiz1>quiz2)
					{
						cout<<"QUIZ 1 SCORE IS HIGHEST i.e: "<<quiz1<<endl;
					}
					else
					{
						cout<<"QUIZ 2 SCORE IS HIGHEST i.e: "<<quiz2<<endl;
					}
				}
				else if(choice2==2)
				{
					if(quiz1<quiz2)
					{
						cout<<"QUIZ 1 SCORE IS LOWEST i.e: "<<quiz1<<endl;
					}
					else
					{
						cout<<"QUIZ 2 SCORE IS LOWEST i.e: "<<quiz2<<endl;
					}
				}
			}
			
			else if(choice==2)
			{
				cout<<"1) HIGHEST SCORE."<<endl<<"3) LOWEST SCORE."<<endl;
				cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				cout<<"ENTER YOUR CHOICE: ";
				cin>>choice2;
				cout<<"---------------------------------------------------------------------------------------------------"<<endl;
				if(choice2==1)
				{
					if(mid1>mid2)
					{
						cout<<"MID 1 SCORE IS HIGHEST i.e: "<<mid1<<endl;
					}
					else
					{
						cout<<"MID 2 SCORE IS HIGHEST i.e: "<<mid2<<endl;
					}
				}
				else if(choice2==2)
				{
					if(mid1<mid2)
					{
						cout<<"MID 1 SCORE IS LOWEST i.e: "<<mid1<<endl;
					}
					else
					{
						cout<<"MID 2 SCORE IS LOWEST i.e: "<<mid2<<endl;
					}
				}
				
		}
	}
	//To read data from file
	//This will be called before Score function
		scorecheck(char c[15])
		{
			ifstream i;
			i.open("School.txt");
			if(i.is_open())
			{
				i.read((char*)this,sizeof(*this));
				while(!i.eof())
				{
					if(!strcmp(this->id,c))
					{
						score();
					}
					i.read((char*)this,sizeof(*this));
				}				
			}
		}
		//operator Overloading
		student operator =(student s3)
		{
			strcpy(id,s3.id);
			strcpy(name,s3.name);
			gender=s3.gender;
			quiz1=s3.quiz1;
			quiz2=s3.quiz2;
			quizscore=s3.quizscore;
			mid1=s3.mid1;
			mid2=s3.mid2;
			quizscore=s3.quizscore;
			finalscore=s3.finalscore;
			return s3;
		}
		//To Sort data in descending order
		sort(int i)
		{
			fstream f;
			f.open("School.txt",ios::in|ios::ate);
			if(f.is_open())
			{
				f.seekg(0);
				f.seekp(f.tellp()+sizeof(*this)*i);
				f.read((char*)this,sizeof(*this));
			}
			else
			{
				cout<<"FILE NOT FOUND....."<<endl;
			}
		}
		//To Count Total records
		counting()
		{
			ifstream i;
			int count=0;
			i.open("School.txt",ios::in);
			if(i.is_open())
			{
				i.read((char*)this,sizeof(*this));
				while(!i.eof())
				{
					count++;
					i.read((char*)this,sizeof(*this));
				}
			}
			return count;
		}
		
};

int main()
{
	//Menu
	system("CLS");
	int num,choice;
	cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"                                             **MENU**"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"01: ADD STUDENTS RECORD."<<endl<<"02: DELETE STUDENTS RECORD."<<endl<<"03: UPDATE STUDENTS RECORD."<<endl<<"04: SEARCH STUDENTS RECORD."<<endl;
	cout<<"05: VIEW ALL RECORDS."<<endl<<"06: CALCULATES AVERAGE OF STUDENTS SCORE."<<endl<<"07: DISPLAY THE HIGHEST/LOWEST SCORE IN PARTICULAR EVALUTION."<<endl;
	cout<<"08: SORTING OF STUDENTS BASED ON FINAL SCORE."<<endl<<"09: TO SEE NUMBER OF RECORDS."<<endl<<"10: EXIT"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"ENTER YOUR CHOICE: ";
	cin>>choice;
	if(choice==1)
	{
		system("CLS");
		cout<<"ENTER NUMBER OF STUDENTS YOU WANT TO ADD INFORMATION: ";
		cin>>num;
		student s[num];
		for(int i=0;i<num;i++)
		{
			s[i].getdata();
		}
		char sel;
		cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
		cin>>sel;
		if(sel=='y'||sel=='Y')
		{
			main();
		}
		else if(sel=='n'||sel=='N')
		{
			system("CLS");
			cout<<"THANKYOU..."<<endl;
		}
	}
	else if(choice==2)
	{
		system("CLS");
		student s;
		char id[15];
		cout<<"ENTER STUDENTS ID: ";
		cin>>id;
		s.deleterecord(id);
		char sel;
		cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
		cin>>sel;
		if(sel=='y'||sel=='Y')
		{
			main();
		}
		else if(sel=='n'||sel=='N')
		{
			system("CLS");
			cout<<"THANKYOU..."<<endl;
		}
	}
	else if(choice==3)
	{
		system("CLS");
		student s;
		char id[15];
		cout<<"ENTER STUDENTS ID: ";
		cin>>id;
		s.updaterecord(id);
		char sel;
		cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
		cin>>sel;
		if(sel=='y'||sel=='Y')
		{
			main();
		}
		else if(sel=='n'||sel=='N')
		{
			system("CLS");
			cout<<"THANKYOU..."<<endl;
		}
	}
	else if(choice==4)
	{
		system("CLS");
		student s;
		char id[15];
		cout<<"ENTER STUDENTS ID: ";
		cin>>id;
		s.search(id);
		char sel;
		cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
		cin>>sel;
		if(sel=='y'||sel=='Y')
		{
			main();
		}
		else if(sel=='n'||sel=='N')
		{
			system("CLS");
			cout<<"THANKYOU..."<<endl;
		}
	}
	else if(choice==5)
	{
		system("CLS");
		student s;
		s.read();
		char sel;
		cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
		cin>>sel;
		if(sel=='y'||sel=='Y')
		{
			main();
		}
		else if(sel=='n'||sel=='N')
		{
			system("CLS");
			cout<<"THANKYOU..."<<endl;
		}
	}
	else if(choice==6)
	{
		system("CLS");
		student s;
		char id[15];
		cout<<"ENTER STUDENTS ID: ";
		cin>>id;
		s.average(id);
		char sel;
		cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
		cin>>sel;
		if(sel=='y'||sel=='Y')
		{
			main();
		}
		else if(sel=='n'||sel=='N')
		{
			system("CLS");
			cout<<"THANKYOU..."<<endl;
		}
	}
	else if(choice==7)
	{
		system("CLS");
		student s;
		char id[15];
		cout<<"ENTER STUDENTS ID: ";
		cin>>id;
		s.scorecheck(id);
		char sel;
		cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
		cin>>sel;
		if(sel=='y'||sel=='Y')
		{
			main();
		}
		else if(sel=='n'||sel=='N')
		{
			system("CLS");
			cout<<"THANKYOU..."<<endl;
		}
	}	
	else if(choice==8)
	{
		system("CLS");
		int num,i,j;
		student temp;
		num=temp.counting();
		student s[num];
		for(i=0;i<num;i++)
		{
			s[i].sort(i);
			
		}
			for(int i=0;i<num;i++)
			{
				for(int j=0;j<num;j++)
				{
					if(s[i].getfinalscore()>s[j].getfinalscore())
					{
						temp.operator=(s[j]);
						s[j].operator=(s[i]);
						s[i].operator=(temp);
					}
				}
			}
			
			for(i=0;i<num;i++)
			{
				s[i].print();
			}
			char sel;
			cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
			cin>>sel;
			if(sel=='y'||sel=='Y')
			{
				main();
			}
			else if(sel=='n'||sel=='N')
			{
				system("CLS");
				cout<<"THANKYOU..."<<endl;
			}
		}
		else if(choice==9)
		{
			int count;
			student s;
			count=s.counting();
			cout<<"TOTAL RECORDS ARE: "<<count<<endl;
			char sel;
			cout<<"FOR MENU PRESS Y ELSE PRESS N: ";
			cin>>sel;
			if(sel=='y'||sel=='Y')
			{
				main();
			}
			else if(sel=='n'||sel=='N')
			{
				system("CLS");
				cout<<"THANKYOU..."<<endl;
			}
		}	
		else if(choice==10)
		{
			cout<<"THANKYOU..."<<endl;
		}
	}

