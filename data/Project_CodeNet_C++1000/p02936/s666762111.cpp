//SkGeN
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstring>
#include<climits>
#include<deque>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> p64;
typedef vector<ll> v64;
const int N = 2 * 1e5 + 10;
const ll inf = 1e18 + 100;
const ll mod = 1e9 + 7;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,s,e) for(long long i=s;i<=e;i++)
#define brep(i,s,e) for(long long i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define DANGER std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll> ed[N];
ll val[N] , vis[N];
ll n , q;

void dfs(ll node , ll par , ll vv) {
	ll sum = vv;
	val[node] += sum;
	for(auto i : ed[node]) {
		if(i == par) continue;

		dfs(i , node , val[node]);
	}
}

void solve() {
	cin>>n>>q;
	for(int i = 0; i < n - 1; i++) {
		ll u ,v ;
		cin>>u>>v;
		ed[u].pb(v);
		ed[v].pb(u);
	}

	for(int i = 0 ; i < q ; i++) {
		ll node , vv ;
		cin>>node>>vv;
		val[node] += vv;
	}


	dfs(1,-1 , 0);

	for(int i = 1; i <= n ; i++) {
		cout<<val[i]<<" ";
	}
}
int main()
{
	DANGER;
	ll t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}
return 0;
}
//---->O ,,