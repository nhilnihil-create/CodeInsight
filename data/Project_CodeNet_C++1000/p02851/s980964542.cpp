#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,k;
	cin>>n>>k;
	ll a[n];ll pre[n+1];
	memset(pre, 0, sizeof pre);
	for(int i=0;i<n;i++)
	cin>>a[i];
	pre[0]=0;
	for(int i=1;i<=n;i++)
	pre[i]=pre[i-1]+a[i-1];
	for(int i=0;i<=n;i++)pre[i]=(pre[i]-i+k)%k;
	
	map<ll, ll> cnt;ll ans=0;
	for(int i=0;i<=n;i++)
	{
		if(i-k>=0)cnt[pre[i-k]]--;
		ans+=cnt[pre[i]];
		cnt[pre[i]]++;
	}
	cout<<ans;
	
}