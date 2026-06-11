#include<bits/stdc++.h>
using namespace std;
int n,a[100100];
long long sum[100100];
long long ans=0;
int main()
{
	cin>>n;
	for(int i=0;i<=n;i++) cin>>a[i];
	for(int i=n;i>=0;i--) sum[i]=sum[i+1]+a[i];
	long long now=1;ans=0;
	for(int i=0;i<=n;i++)
	{
		if(a[i]>now) return puts("-1"),0;
		ans+=now;now-=a[i];
		now=min(now+now,sum[i+1]);
	}
	cout<<ans<<endl;
}