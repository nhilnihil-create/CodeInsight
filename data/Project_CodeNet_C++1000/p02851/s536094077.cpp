#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const ll INF = ll(1e15)+10;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;

using Graph = vector<vector<P>>;

int main() {
	ll N, K; cin >> N >> K;
	Vll C(N+1);
	rep(i, N) {
		ll a;
		cin >> a;
		C[i+1] = (C[i] + a - 1) % K;
	}

	map<ll, V> cnt;
	rep(i, N+1) {
		cnt[C[i]].push_back(i);
	}

	ll ans = 0;
	for (auto x : cnt) {
		auto vec = x.second;
		rep(i, vec.size()) {
			ans += upper_bound(ALL(vec), vec[i]+K-1) - (vec.begin()+i) - 1;
		}
	}
  cout << ans << endl;
}