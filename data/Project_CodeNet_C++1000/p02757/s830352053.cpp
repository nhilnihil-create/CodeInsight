#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

ll fastPow(ll a, ll b, ll p) {
	ll ret = 1;
 	while(b) {
		if(b & 1) ret = ret * a % p;
		b >>= 1, a = a * a % p;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	#endif

	int n, p;
	string str;
	cin >> n >> p >> str;
	if(p == 2 || p == 5) {
		ll ans = 0;
		for(int i = 0; i < n; i++)
			if((str[i] - '0') % p == 0) ans += i + 1;
		cout << ans << '\n'; exit(0);
	}

	int inv = fastPow(10, p - 2, p), pot = 1, zer = 0;
	vector<int> cnd(p);
	ll ans = 0;
	for(auto el: str) {
		el -= '0';
		cnd[zer]++;
		int tomv = pot * int(el) % p;
		zer = (p + zer - tomv) % p;
		ans += cnd[zer];
		pot = pot * inv % p;
	}
	cout << ans << '\n';
}

