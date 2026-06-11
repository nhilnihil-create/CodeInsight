#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T = double>
using point = complex<T>; // 2D point only

using ll = long long;
using ull = unsigned long long;
using ldob = long double;

template <typename T = int>
using ii = pair<T,T>;
template <typename T = int>
using iii = pair<T,ii<T>>;
template <typename T = int>
using ii_i = pair<ii<T>,T>;
template <typename T = int>
using vi = vector<T>;
template <typename T = int>
using vvi = vector<vi<T>>;
template <typename T = int>
using vii = vector<ii<T>>;
template <typename T = int>
using viii = vector<iii<T>>;
template <typename T = int>
using lim = numeric_limits<T>;

#define re real()
#define im imag()
#define fi first
#define se second
#define all(v) v.begin(), v.end()

// OST
template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// from: https://codeforces.com/blog/entry/62393
// struct custom_hash {
// 	static uint64_t splitmix64(uint64_t x) {
// 		// http://xorshift.di.unimi.it/splitmix64.c
// 		x += 0x9e3779b97f4a7c15;
// 		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// 		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// 		return x ^ (x >> 31);
// 	}

// 	size_t operator()(uint64_t x) const {
// 		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// 		return splitmix64(x + FIXED_RANDOM);
// 	}
// };

const int INF = ~(1<<31);
const ll LINF = (1LL << 60);
const long double EPS = 1e-9;
const long double PI = acos(-1);

const int N = 15;
const int NN = 101;
const int MOD = 1e9+7;
const int IMAX = 1e9+7;
const ll LMAX = 1e15+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
const int dx8[8] = {-1,-1,-1,0,0,1,1,1};
const int dy8[8] = {-1,0,1,-1,1,-1,0,1};

ll n, m, x, c[N], a[N][N];

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0); // cout.tie(0);
	// cout.precision(2); cout << fixed;

	cin >> n >> m >> x;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	ll ans = LINF;
	for (int msk = 0; msk < (1<<n); ++msk) {
		vector<ll> brain(m, 0);
		ll cost = 0;
		for (int i = 0; i < n; ++i) {
			if (msk&(1<<i)) {
				cost += c[i];
				for (int j = 0; j < m; ++j) {
					brain[j] += a[i][j];
				}
			}
		}
		bool ok = true;
		for (int i = 0; i < m; ++i)
			ok &= brain[i] >= x;
		if (ok)
			ans = min(ans, cost);
	}

	cout << (ans == LINF ? -1 : ans) << endl;

	return 0;
}