#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,a,b,c;
	cin>>a>>b>>c;
	if(a==b&&b==c)
		cout<<"No";
	else if(a==b||a==c||b==c)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}