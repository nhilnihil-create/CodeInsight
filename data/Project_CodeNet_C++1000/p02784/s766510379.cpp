#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	long long H,N,m,ans=0;
	cin>>H>>N;
	for(int i=1;i<=N;i++)	
	{
		cin>>m;	
		ans+=m;
	}
	if(ans>=H)cout<<"Yes";
	else cout<<"No";
	return 0;
}