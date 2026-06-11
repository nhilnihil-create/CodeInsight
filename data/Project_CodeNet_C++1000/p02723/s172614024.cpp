#include<iostream>
using namespace std;
main()
{
	string str1;
	cin>>str1;
	int len=str1.length();
	if(len==6)
	{ 
		char c3= str1.at(2);
		char c4= str1.at(3);
		char c5= str1.at(4);
		char c6= str1.at(5);
		if(c3==c4 && c5==c6)
		{
		     cout<<"Yes"<<"\n";
		 }
		else
		{
			cout<<"No"<<"\n";
		}
	} 
}
