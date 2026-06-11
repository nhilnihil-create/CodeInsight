#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b,c;
	cin>>a>>b>>c;
	if(a==b)
	{
		if(b!=c)
		{
			cout<<"Yes";
			return 0;
		}
		else 
		{
			cout<<"No";
			return 0;
		}
	} 
	if(b==c)
	{
		if(a!=b)
		{
			cout<<"Yes";
			return 0;
		}
		else
		{
			cout<<"No";
			return 0;
		}
	}
	if(a==c)
	{
		if(a!=b)
		{
			cout<<"Yes";
			return 0;
		}
		else 
		{
			cout<<"No";
			return 0;
		}
	}
	else cout<<"No";
    return 0;
} 