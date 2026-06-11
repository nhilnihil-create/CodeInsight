#include <bits/stdc++.h>
using namespace std;

int f[2005],n,mod=1e9+7;

int main()
{
	cin>>n;
	f[0]=1,f[1]=0,f[2]=0,f[3]=1;
	for(int i=4;i<=n;i++) f[i]=(f[i-1]+f[i-3])%mod;
	cout<<f[n];
	return 0;
}