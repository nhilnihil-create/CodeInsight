#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define repa(i, a, b) for (auto i = (a); i <= (b); i++)
#define repd(i, a, b) for (auto i = (a); i >= (b); i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define zero(a)  memset((a), 0, sizeof (a))
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back

constexpr auto inf = numeric_limits<int>().max() - 1;
constexpr auto llinf = numeric_limits<ll>().max() - 1LL;

template<typename ForwardIterator>
void dump(ForwardIterator st, ForwardIterator en) {
	for (auto it = st; it != en; it++) {
		cout << *it << " ";
	}
	cout << endl;
}

template<typename ForwardIterator>
void dump_map(ForwardIterator st, ForwardIterator en) {
	for (auto it = st; it != en; it++) {
		cout << (*it).first << ":" << (*it).second << " ";
	}
	cout << endl;
}
template<typename T>
void debug(initializer_list<T> list) {
  for (auto el : list) {
    cout << el << " ";
  }
  cout << endl;
}

constexpr ll mod = ll(1e9 + 7);

ll mult(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }

ll power(ll a, ll b) {
	ll result = 1LL;
	while (b) {
		if (b % 2LL) result = mult(result, a);
		a = mult(a, a);
		b /= 2LL;
	}
	return result;
}

ll divide(ll a, ll b) { return mult(a, power(b, mod - 2)); }

ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }

ll subtract(ll a, ll b) { return ((a - b) % mod + mod) % mod; }

int n, m, q;
struct quad {
	int a, b, c, d;
	quad(int _a, int _b, int _c, int _d) : a{_a}, b{_b}, c{_c}, d{_d} {}
};
vector<quad> quads;

int costof(vi &nums) {
	int cost = 0;
	for (auto e : quads) {
		if (nums[e.b - 1] - nums[e.a - 1] == e.c) cost += e.d;
	}
	return cost;
}

int brute(vi &nums) {
	if (sz(nums) == n) {
		return costof(nums);
	} else {
		int mxm = -2;
		repa(i, nums[sz(nums) - 1], m) {
			nums.pb(i);
			int cost = brute(nums);
			mxm = max(cost, mxm);
			nums.pop_back();
		}
		return mxm;
	}
}

void solve() {
	cin >> n >> m >> q;
	quads.clear();
	rep(i, q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		quads.pb({a, b, c, d});
	}
	int mxm = 0;
	for (int i = 1; i <= m; i++) {
		auto nums = vi(1, i);
		mxm = max(mxm, brute(nums));
	}
	cout << mxm;
	cout << "\n";
}

#define REPEAT 0
#define CASE 0

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#if REPEAT
		int t;
		cin >> t;
		repa(i, 1, t) {
			#if CASE
				cout << "Case #" << i << ": ";
			#endif
			solve();
		}
	#else
		solve();
	#endif
	return 0;
}
