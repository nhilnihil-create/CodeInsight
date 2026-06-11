// template {{{
#include <bits/stdc++.h>
using namespace std;

// #define int long long

#define GET_MACRO(a, b, c, d, NAME, ...) NAME
#define REP2(i, n) REP3(i, 0, n)
#define REP3(i, a, b) REP4(i, a, b, 1)
#define REP4(i, a, b, s) for (ll i = (a); i < (ll)(b); i += s)
#define RREP2(i, n) RREP3(i, 0, n)
#define RREP3(i, a, b) for (ll i = (b) - 1; i >= (ll)(a); i--)

#define rep(...) GET_MACRO(__VA_ARGS__, REP4, REP3, REP2)(__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__,, RREP3, RREP2)(__VA_ARGS__)
#define eb emplace_back
#define ef emplace_front
#define pb pop_back
#define pf pop_front
#define all(c) begin(c), end(c)
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define popcnt __builtin_popcountll

#ifdef DEBUG
	#define dump(x) cerr << #x " = " << x << endl;
#else
	#define dump(x)
#endif

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;

template<typename T>
using maxheap = priority_queue<T, vector<T>, less<T>>;

template<typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9 + 10;
const ll LLINF = 1e18 + 10;

const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

template<typename T>
inline T sq(T x){
	return x * x;
}

template<typename T, typename U>
inline bool chmax(T &x, U y){
	if (x >= y) return false;
	x = y;
	return true;
}

template<typename T, typename U>
inline bool chmin(T &x, U y){
	if (x <= y) return false;
	x = y;
	return true;
}

template<typename T>
inline T& sort(T &c){
	sort(all(c));
	return c;
}

template<typename T>
inline T& reverse(T &c){
	reverse(all(c));
	return c;
}

template<typename T>
inline T& unique(T &c){
	sort(all(c));
	c.erase(unique(all(c)), end(c));
	return c;
}

template<typename T>
inline T sorted(const T &c){
	T d = c;
	return move(sort(d));
}

template<typename T>
inline T reversed(const T &c){
	T d = c;
	return move(reverse(d));
}

template<typename T>
inline T uniqued(const T &c){
	T d = c;
	return move(unique(d));
}

ll modpow(ll x, ll e, ll mod = 1000000007){
	ll res = 1;
	e %= mod - 1;
	while (e){
		if (e & 1) res = res * x;
		x = x * x;
		e >>= 1;
	}
	return res;
}

inline ll in(){
	ll x;
	scanf("%lld", &x);
	return x;
}

inline double inD(){
	double x;
	scanf("%lf", &x);
	return x;
}

inline string inS(){
	static char s[1024];
	scanf("%s", s);
	return s;
}

pair<ll, ll> rot45(ll x, ll y){
	return mp(x + y, x - y);
}

pair<ll, ll> rot45inv(ll u, ll v){
	return mp((u + v) / 2, (u - v) / 2);
}

template<typename T, size_t N>
struct print_tuple {
	static void print(const T &t, ostream &os){
		print_tuple<T, N - 1>::print(t, os);
		os << " " << get<N - 1>(t);
	}
};

template<typename T>
struct print_tuple<T, 1> {
	static void print(const T &t, ostream &os){
		os << get<0>(t);
	}
};

template<typename ...Args>
ostream& operator<<(ostream &os, const tuple<Args...> &t){
	print_tuple<tuple<Args...>, tuple_size<tuple<Args...>>::value>::print(t, os);
}
// }}}
// range sum query {{{
template<typename T>
class RangeSumQuery {
public:
	RangeSumQuery(){}
	RangeSumQuery(int n, T init, function<T(const T&, const T&)> merge = plus<T>()){
		for (size = 1; size < n; size <<= 1);
		val.assign(size * 2 - 1, init);
		this->init = init;
		this->merge = merge;
	}

	void update(int k, T x){
		k += size - 1;
		val[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			val[k] = merge(val[k * 2 + 1], val[k * 2 + 2]);
		}
	}

	T sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}

	T sum(int l, int r, int k, int a, int b){
		if (r <= a || b <= l) return init;
		if (l <= a && b <= r) return val[k];
		int m = (a + b) / 2;
		T vl = sum(l, r, k * 2 + 1, a, m);
		T vr = sum(l, r, k * 2 + 2, m, b);
		return vl + vr;
	}

private:
	int size;
	T init;
	vector<T> val;
	function<T(const T&, const T&)> merge;
};
// }}}

int main()
{
	int n = in(), q = in();
	vector<int> a(n, 0);
	RangeSumQuery<int> tr(n, 0);
	rep(i, q){
		int com = in(), x = in() - 1, y = in();
		if (com == 0) tr.update(x, a[x] += y);
		else cout << tr.sum(x, y) << endl;
	}
}