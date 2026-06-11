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
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;
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

int N, K;
ll inp[1000001];

vector<ll> dividedNum(ll n){
    //n == 2 && n == 1の時エラー
    vector<ll> res;
	ll lim = sqrt(n)+1;
    for(ll i=1; i<lim; i++){
        if(n%i==0){
            res.push_back(i);
            if(i != n / i && lim <= n/i){
                res.push_back(n/i);
            }
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);
	memr(inp, 0);
	cin >> N>> K;
	ll sum = 0;
	rep(i, N){
		cin >> inp[i];
		sum += inp[i];
	}

	vector<ll> divs = dividedNum(sum);

	ll ans = 0;
	for(ll div : divs){
		vector<ll> mp;
		ll tmp = 0;
		ll tmp2 = 0;
		rep(i, N){
			ll num = inp[i] % div;
			mp.push_back(num);
			tmp2 += num;
		}
		sort(ALL(mp));
		int k = 0;
		print(tmp2 / div, tmp2);
		rrep(i, mp.size()){
			if(k == tmp2 / div) break;
			k++;
			tmp += div - mp[i];
		}
		print(tmp);
		if(tmp > K) continue;
		chmax(ans, div);
	}

	cout << ans << endl;



	return 0;
}
