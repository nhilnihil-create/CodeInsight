#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

int main(){
	ll n, m, u, v, s, t; cin >> n >> m;
	vector<vector<ll>> conn(3*n);
	REP(i,m){
		cin >> u >> v;
		conn[3*u-3].pb(3*v-2);
		conn[3*u-2].pb(3*v-1);
		conn[3*u-1].pb(3*v-3);
	}
	cin >> s >> t;
	vector<ll> ansl(3*n,-1);
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
	ansl[3*s-3] = 0;
	q.push({0, 3*s-3});
	while (q.size()>0){
		ll nowat = q.top().at(1);
		ll dist = q.top().at(0);
		ll edas = conn[nowat].size();
		REP(i,edas){
			ll nex = conn[nowat][i];
			if (ansl[nex]==-1 || ansl[nex]>1+dist){
				q.push({1+dist,nex});
				ansl[nex] = 1+dist;
			}
		}
		q.pop();
	}
	if (ansl[3*t-3]==-1){
		cout << -1 << endl;
	}
	else{
		cout << ansl[3*t-3]/3 << endl;
	}
}