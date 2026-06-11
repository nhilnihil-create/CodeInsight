#include <bits/stdc++.h>

using namespace std;

#define mod1 1000000007
#define mod2 998244353
#define int long long int
#define pii pair<int,int>
#define vpii vector<pii>
#define vi vector<int>
#define fi first
#define se second
#define psb push_back
#define ppb pop_back
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(),x.end()
// #define endl "\n"

const int maxn=2e5+5;


void solve()
{
	int n;
	cin>>n;
	int ans=0;
	for(int l=1;l<=n;l++)
		ans += (n-l+1)*(l+n)/2 - (n-l+1)*(l-1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u>v)
			swap(u,v);
		ans -= u*(n-v+1);
	}
	cout<<ans<<endl;
}	

int32_t main()
{
	fio;
	int t;
	// cin>>t;
	t=1;
	while(t--)
	{
		solve();
	}
}