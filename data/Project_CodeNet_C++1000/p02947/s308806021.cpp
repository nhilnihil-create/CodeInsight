#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+3;
string s;
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n;
	cin>>n;
	map<string,int> f;int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		if(f[s])ans+=f[s];
		f[s]++;

	}
	cout<<ans;
}