#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; print(tail...); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; ll k; read(n, k);
	vector<int> v(n), v2(2 * n);
	rep(i, 0, n) read(v[i]), v2[i] = v2[n + i] = v[i];

	ll ans0 = 0, ans1 = 0, ans = 0;

	rep(i, 0, n) rep(j, i + 1, n) if (v[i] > v[j]) ans0++;
	rep(i, 0, n) rep(j, n, 2 * n) if (v2[i] > v2[j]) ans1++;

	const ll mod = 1000000007;

	ans += ans0 * k % mod;
	ans += ans1 * (k * (k - 1) / 2 % mod) % mod;

	cout << ans%mod << endl;
}
