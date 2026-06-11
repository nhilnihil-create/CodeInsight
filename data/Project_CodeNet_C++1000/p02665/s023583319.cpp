#include<bits/stdc++.h>
using namespace std;
long long n,a[101010],s[101010],ans,nw;
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=0;i--)
	{
		s[i]=s[i+1]+a[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(i!=0)
		{
			nw=min(nw*2,s[i]);
		}
		else
		{
			nw=1;
		}
		ans+=nw;
		if(nw<a[i])
		{
			cout<<-1<<endl;
			return 0;
		}
		nw-=a[i];
	}
	cout<<ans<<endl;
	return 0;
}