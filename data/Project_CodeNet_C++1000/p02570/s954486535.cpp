#include<iostream>
using namespace std;
int main()
{
	long double d,t,s,T;
	cin>>d>>t>>s;
	T=(long double)d/(long double)s;
	if(T<=t)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
