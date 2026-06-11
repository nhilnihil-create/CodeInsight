#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ALL(x) x.begin(),x.end()
#define rALL(x) x.rbegin(),x.rend()
#define endl '\n'
#define DEBUG

template<typename T> void DBG(const char* name, T&& H) {
	cerr << name << " = " << H << ')' << endl;
}

template<typename T, typename... Args> void DBG(const char* names, T&& H, Args&&... args) {
	const char* NEXT = strchr(names+1, ',');
	cerr.write(names, NEXT-names) << " = " << H << " |";
	DBG(NEXT+1, args...);
}

#ifdef DEBUG
	#define dbg(...) cerr << __FUNCTION__ << ' ' <<__LINE__ << " : (", DBG(#__VA_ARGS__, __VA_ARGS__)
#else
	#define dbg(...)
#endif

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int INF = 1e8;
const int maxN = 2001;

ll n;
vector<pair<ll, ll>> a;
vector<vector<ll>> dp(maxN, vector<ll>(maxN, -1));

ll rec(ll idx, ll L, ll R) {
	if(dp[L][R] != -1) return dp[L][R];
	if(L == R) return a[idx].first * abs(L-a[idx].second); 
	ll ans = max((a[idx].first * abs(L-a[idx].second)) + rec(idx+1, L+1, R), (a[idx].first * abs(R-a[idx].second)) + rec(idx+1, L, R-1));
	dp[L][R] = ans;
	return ans;
}

void Solve() {
	cin >> n;
	for(ll i = 0; i < n; i ++) {
		pair<ll, ll> t;
		cin >> t.first;
		t.second = i;
		a.push_back(t);
	}
	sort(rALL(a));
	cout << rec(0, 0, n-1) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tt = 1;
	while(tt --) {
		Solve();
	}
	
	return 0;
}