#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<12, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vi a(n), b;
	ll ans = 0, t = 0;
	for(auto &i : a) cin >> i, t ^= i;
	ans += t;
	t = (1ll<<60) - 1 - t;
	for(auto &i : a) {
		i&=t;
		for(auto j : b) i = min(i, i^j);
		if(i) b.pb(i);
	}
	t = 0;
	for(auto &i : b) t = max(t, t^i);
	ans += t<<1;
	cout << ans;
	return 0;
}
