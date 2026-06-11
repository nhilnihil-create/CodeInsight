#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b&&a==c)
	{
		cout<<"No";
		return 0;
	}
	if(a==b||a==c||b==c)
	{
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
}