#include<iostream>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	if(a==b)
		if(a!=c)
		{
			cout<<"Yes";
			return 0;
		}
	if(a==c)
		if(a!=b)
		{
			cout<<"Yes";
			return 0;
		}
	if(b==c)
		if(b!=a)
		{
			cout<<"Yes";
			return 0;
		}
	cout<<"No";
}