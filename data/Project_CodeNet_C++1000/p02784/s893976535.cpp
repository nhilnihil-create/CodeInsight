#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,i,ans=0;
	cin>>a>>b;
	for(i=1;i<=b;i++)
	{
		cin>>c;
		ans+=c;
	}
	if(ans>=a)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}