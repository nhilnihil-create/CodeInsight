#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int par[222222];
int dp[222222];
const int INF=int(1e9);
set<int> a[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	string s; cin>>s;
	dp[n]=0;
	set<int> S; S.insert(n);
	a[0].insert(n);
	for(int i=n-1;i>=0;i--)
	{
		dp[i]=INF;
		if(s[i]=='1') continue;
		auto it = S.upper_bound(i+m);
		if(it==S.begin()) continue;
		it--;
		dp[i]=dp[(*it)]+1;
		a[dp[i]].insert(i);
		S.insert(i);
	}
	if(dp[0]>=INF){cout<<-1<<'\n'; return 0;}
	int cur=0;
	vi v;
	while(cur!=n)
	{
		int d = dp[cur];
		auto it = a[d-1].lower_bound(cur);
		v.pb((*it)-cur);
		cur=(*it);
	}
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i];
		if(i+1<v.size()) cout<<' ';
	}
	cout<<'\n';
}
