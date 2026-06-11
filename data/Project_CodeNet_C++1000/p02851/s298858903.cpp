#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k,ans=0;
int a[200005],pre[200005];

map<int,int> m;

signed main()
{
	cin>>n>>k;
	if (k==1)  return cout<<0<<endl,0;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=n;i++)  a[i]--;
	for (int i=1;i<=n;i++)  pre[i]=(pre[i-1]+a[i])%k;

	m[0]=1;
	for (int i=1;i<=n;i++)
	{
		ans+=m[pre[i]];
		m[pre[i]]++;
		if (i>=k-1)  m[pre[i-k+1]]--;
	}
	cout<<ans<<endl;
	
	return 0;
}