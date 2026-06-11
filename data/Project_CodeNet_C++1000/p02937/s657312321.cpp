#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif

	string s,t;cin>>s>>t;
	vector<int> id[26];
	int n=s.length();int m=t.length();
	for(int i=0;i<n;i++)
	{
		id[s[i]-'a'].push_back(i+1);
	}

	for(auto i:t){if(id[i-'a'].size()==0){cout<<-1;return 0;}}


	int cnt=1,ans=0;
	

	for(auto i:t)
	{
		int now=i-'a';
		auto it=lower_bound(id[now].begin(),id[now].end(),cnt);
		if(it==id[now].end())
		{
			ans+=(n-cnt+1);
			cnt=1;
		}
		it=lower_bound(id[now].begin(),id[now].end(),cnt);
		ans+=*it-cnt+1;
		cnt=*it+1;
	}
	cout<<ans;

}