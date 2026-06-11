#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;

const int mod=1e9+7;
ll n;
ll f[2333];

int main()
{
	cin>>n;
	f[0]=1;
	f[1]=0;
	f[2]=0;
	for(int i=3;i<=n;i++)
		for(int j=0;j+3<=i;j++)
		{
			f[i]+=f[j];
			f[i]%=mod;
		}
	cout<<f[n];
}