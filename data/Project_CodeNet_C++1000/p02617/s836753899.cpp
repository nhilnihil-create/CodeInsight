#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r", stdin);
		freopen("out","w",stdout);
	#endif

	int n;
	cin>>n;
	int u,v;

	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=i*(n-i+1);
	}

	//edges
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		if(u>v)swap(u,v);
		int sub=(n-v+1)*u;
		ans-=sub;
	}
	cout<<ans;


}