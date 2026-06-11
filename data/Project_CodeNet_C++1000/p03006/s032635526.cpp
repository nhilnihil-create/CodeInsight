#include <bits/stdc++.h>
#include <iostream>
#include <utility> // pair
#include <string>
#include <vector>
#define MAX_N 51
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define FOR(i, a, b) for(ll i=a; i<b; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REV(i, n) for(ll i=n-1; i>=0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
const ll INF = 9e18;
ll n, x[MAX_N], y[MAX_N];

signed main(){
	cin >> n;
	REP(i, n) cin >> x[i] >> y[i];
	ll ret = INF;
	REP(i, n) REP(j, n){
		if(i == j) continue;
		ll p = x[i] - x[j], q = y[i] - y[j];
		vector<P> e;
		REP(k, n) REP(l, n){
			if(k == l) continue;
			if(x[k] - x[l] == p && y[k] - y[l] == q) e.pb(P(k, l));
		}
		ret = min(ret, n - (ll)e.size());

	}
	if(n == 1) ret = 1;
	cout << ret << endl;
    return 0;
}