#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		ans+=i*(n-i+1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u>v)
			swap(u,v);
		ans-=u*(n-v+1);
	}
	cout<<ans<<endl;
	return 0;
}