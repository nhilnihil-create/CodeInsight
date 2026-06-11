#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using std::string;
using std::vector;
using std::set;
using std::multiset;
using std::unordered_set;
using std::map;
using std::multimap;
using std::unordered_map;
using std::pair;
using std::cin;
using std::cout;

using boost::multiprecision::cpp_int;
using cpp_dec_float_1000 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000, boost::int128_type>>;

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

constexpr char CRLF  = '\n';
constexpr char SPACE = ' ';
constexpr char VECTOR_COUT_SEPARATOR = SPACE;
constexpr ll INF = 1000'000'007;
constexpr int MOD = 1000'000'007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& vc) { for(auto it = vc.begin(); it != vc.end(); ++it) { if (std::next(it) == vc.end()) os << *it; else os << *it << VECTOR_COUT_SEPARATOR; } return os; }
template<class T1, class T2> inline std::ostream & operator<< (std::ostream & os, const std::pair<T1, T2> & p) { return os << p.first << ' ' << p.second; }
template<class T> T modinv(T a, T m) { T b = m, u = 1, v = 0; while (b) { T t = a / b; a -= t * b; boost::swap(a, b); u -= t * v; boost::swap(u, v); } u %= m; if (u < 0) u += m; return u; }
template<class T> inline bool isSosuu(const T& n) { if (n == T(1)) { return false; } for (T i = 2; i*i <= n; ++i) { if (n % i == 0) { return false; } } return true; }
template<class T> vector<vector<T>> split (const vector<T>& S, T delim) { vector<vector<T>> ret{}; vector<T> buff{}; for (auto c : S) { if (c == delim) { if (!buff.empty()) ret.push_back(buff); buff.clear(); } else { buff.push_back(c); } } if (!buff.empty()) ret.push_back(buff); return ret; }
template<class T> inline void printYesNo(const T& t) { cout << (t ? "Yes" : "No") << CRLF; }
template<class T = int64_t> T modpow(T N, T P, T M) { T ret{1}; N %= M; while (P) { if (P & 0x01) { ret *= N; ret %= M; } P >>= 1; N *= N; N %= M; } return ret; }

/** code for assert debug begin */
int gErr = 0;
#define ASSERT(p) if(!(p)){ gErr = 1; }else{ ; }
/** code for assert debug end */

struct Tmp
{
public:
  int N, M;
  Tmp(int N, int M)
  : N(N)
  , M(M)
  {}
};

void solve(void)
{
  int N, M; cin >> N >> M;
  vector<int> S(N+1);
  for (int i = 1; i <= N; ++i) {
    cin >> S[i];
  }
  vector<int> T(M+1);
  for (int i = 1; i <= M; ++i) {
    cin >> T[i];
  }
  vector<vector<ll>> dp(N+1, vector<ll>(M+1));
  vector<vector<ll>> sum(N+1, vector<ll>(M+1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      if (S[i] == T[j]) {
        dp[i][j] = sum[i-1][j-1] + 1;
        dp[i][j] %= MOD;
      }
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j];
      if (sum[i][j] < 0) { sum[i][j] += MOD; }
      sum[i][j] %= MOD;
    }
  }
  auto ans = sum[N][M] + 1;
  cout << ans << CRLF;
  
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
