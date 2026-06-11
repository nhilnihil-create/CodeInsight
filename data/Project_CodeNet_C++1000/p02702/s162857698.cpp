#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
// 型シノニム
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
// 定数
constexpr ll INF   = 1e16;
constexpr ll INM   = 114514;
constexpr ll MOD   = 1e9 + 7;
constexpr ld EPS   = 1e-12;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
// 便利関数
void IOS() { ios::sync_with_stdio(false), cin.tie(0); }
template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, ll t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll mod) {
	if (a > 0) return a % mod;
	if (a % mod == 0) return 0;
	ll x = -a / mod + 1;
	a += x * mod;
	return a % mod;
}
ll powm(ll a, ll b, ll m) {
	if (b == 0) {
		return 1;
	} else if (b % 2 == 0) {
		ll d = powm(a, b / 2, m);
		return (d * d) % m;
	} else {
		return (powm(a, b - 1, m) * a) % m;
	}
}
// 本体

ll a[200002] = {};

int main() {
	IOS();
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	map<ll, ll> mp;
	mp[0]++;
	ll cnt = 1;
	for (int i = 0; i < s.size(); i++) {
		int keta = (int)(s[i] - '0');
		if (i == 0) {
			a[i] = (int)(s[i] - '0');
		} else {
			a[i] = (a[i - 1] + cnt * keta) % 2019;
		}
		cnt *= 10;
		cnt %= 2019;
		mp[a[i]]++;
	}
	ll ans = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		ll unko = (*it).second;
		ans += (unko - 1) * unko / 2;
	}
	dump(ans);
}