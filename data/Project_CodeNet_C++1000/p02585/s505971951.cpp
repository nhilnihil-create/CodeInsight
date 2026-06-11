#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

int32_t main()
{	int ans=-1e18;
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n,k;
	cin>>n>>k;
	vector<int> p(n),c(n);
	for(int i=0;i<n;i++)
		cin>>p[i],p[i]--;
	for(int i=0;i<n;i++)cin>>c[i];

	for(int i=0;i<n;i++)
	{
		int v=i;
		int csum=0,len=0;
		while(1)
		{
			len++;
			csum+=c[v];
			v=p[v];
			if(v==i)break;
		}
		int path=0,cnt=0;
		while(1)
		{
			cnt++;
			path+=c[v];
			if(cnt>k)break;
			int mul=(k-cnt)/len;
			int cur=path+max(0ll,csum)*mul;
			ans=max(ans,cur);
			v=p[v];
			if(v==i)break;
		}


	}
	cout<<ans;
}
