#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;

constexpr int MOD = 1e9+7;

namespace math { namespace integer {

template<class T> T mod_mul(T x, T k, T m) { if(k == 0) { return 0; } if(k % 2 == 0) { return mod_mul((x + x) % m, k / 2, m); } else { return (x + mod_mul(x, k - 1, m)) % m; } }
template<class T> T mod_pow(T x, T n, T mod) { if(n == 0) { return 1; } if(n % 2 == 0) { return mod_pow(mod_mul(x, x, mod) % mod, n / 2, mod); } else { return mod_mul(x, mod_pow(x, n - 1, mod), mod); } }
template<class T> T extgcd(T a, T b, T& x, T& y) { T d = a; if(b != 0) { d = extgcd(b, a % b, y, x); y -= (a / b) * x;} else { x = 1, y = 0; } return d; }
template<class T> T mod_inverse(T x, T mod) { return mod_pow(x, T(mod - 2), mod); /* use fermat */ }
template<class T> T mod_inverse_composite_num_mod(T a, ll mod) { T x, y; extgcd(a, mod, x, y); return (mod + x % mod) % mod; }

}}
using namespace math::integer;

typedef long long ll;
int const inf = INT_MAX / 2;

namespace sort_algorithm {  // not verified

long long inversion_count(int n, vector<int> const& a) {
  long long ret = 0;
  rep(i, n) REP(j, i + 1, n) {
    ret += a[i] > a[j];
  }
  return ret;
}

}

int main() {
  ll N, K; cin >> N >> K;
  vector<int> A(N); rep(i, N) cin >> A[i];
  // X: A 上の転倒数
  // Y_i: A_i -> A で転倒数
  // X * K + Σ_{l=0}^{N-1} Y_i * (Σ_{k=1}^{K-1} k)

  ll ans = (sort_algorithm::inversion_count(N, A) * K) % MOD;

  rep(i, N) {
    vector<int> B;
    ll Y = 0;
    rep(j, N) Y += A[i] > A[j];
    ll p = ((K - 1) * K / 2) % MOD;
    (ans += (Y * p) % MOD) %= MOD;
  }

  cout << ans << endl;
}
