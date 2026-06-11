#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define memr(dp, val) memset(dp, val, sizeof(dp))
using namespace std;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
static const int MAX = 100001;
static const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool int_ceil(T a, T b) { T res = a / b; if(a % b != 0) res++; return res; }
template<typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define print(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define print(...)
#endif

vector<ll> sieve(long long max){ // 0 <= x <= max までの素数を調べ、返す。
    vector<bool> isPrime;
	vector<ll> ret;
    isPrime.resize(max+1,true); // isPrimeに必要な要素数を確保
    isPrime[0] = false; // 0は素数ではない
    isPrime[1] = false; // 1は素数ではない

    for(int i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(isPrime[i])
            for(int j=2; i*j<=max; ++j)
                isPrime[i*j] = false;

	rep(i, isPrime.size()){
		if(isPrime[i]) ret.push_back(i);
	}
    return ret;
}

ll n;
ll ans = 0;
vector<ll> primes;
vector<int> nums;
vector<ll> tes;
int kinds = 0;
void dfs(ll val, ll dep, int s, ll val2){
	ans += (val2) * val;
	ll tmp = n / val;
	int k = s;
	while(1){
		if(tmp < primes[k]) break;
		val2 /= nums[k];
		nums[k]++;
		val2 *= nums[k];
		dfs(val * primes[k], dep+1, k, val2);
		val2 /= nums[k];
		nums[k]--;
		val2 *= nums[k];
		k++;
	}
}


int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	primes = sieve(MAX * 100);
	// print(primes.size());
	nums.resize(primes.size(), 1);
	cin >> n;
	dfs(1, 0, 0, 1);
	cout << ans << endl;



	return 0;
}
