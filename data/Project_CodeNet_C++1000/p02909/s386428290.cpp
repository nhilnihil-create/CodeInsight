#include<iostream>
#include<string>
using namespace std;
main()
{
	string s;
	cin>>s;
	if(s=="Sunny")
	{
		cout<<"Cloudy"<<endl;
	}
	else if(s=="Cloudy")
	{
		cout<<"Rainy"<<endl;
	}
	else if(s=="Rainy")
	{
		cout<<"Sunny"<<endl;
	}
}
