#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
long long f[500010];
long long tot=0;
long long ans=0;
int main()
{
	cin>>s;
	long long len=s.length();
	bool left=false;
	char chr='>';
	long long fuhao=1;
	if (s[0]=='<')
	{
		left=true;
		chr='<';
	}
	for (long long i=1;i<len;++i)
	{
		if (s[i]!=chr)
		{
			tot++;
			f[tot]=fuhao;
			fuhao=1;
			chr=s[i];
		}
		else
		{
			fuhao++;
		}
	}
	if (fuhao!=0)
	{
		tot++;
		f[tot]=fuhao;
	}
	long long root=0;
	if (left)
	{
		root=max(f[2],f[1]);
		ans+=((1+f[1]-1)*(f[1]-1))/2;
		left=false;
	}
	else
	{
		ans=((1+f[1])*f[1])/2;
		root=0;
		left=true;
	}
	for (long long i=2;i<=tot;++i)
	{
		if (left)
		{
			root=max(f[i],f[i+1]);
			ans+=((1+f[i]-1)*(f[i]-1))/2;
			left=false;
		}
		else
		{
			ans+=((1+f[i]-1)*(f[i]-1))/2;
			ans+=root;
			root=0;
			left=true;
		}
	}
	ans+=root;
	cout<<ans<<"\n";
    return 0;
}