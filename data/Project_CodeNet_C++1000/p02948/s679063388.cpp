#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll A,ll B) {if(!B)return A;return gcd(B,A%B);}
int main()
{
	ll n,m;
	cin>>n>>m;
	vii v(m+1);
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(a <= m)v[a].pb(b);
	}
	ll ans = 0;
	priority_queue<int>pq;
	for(auto x : v){
		for(auto y:x)pq.push(y);
		if(!pq.empty()){
			ans+=pq.top();
			pq.pop();
		}
	}
	cout<<ans;
}