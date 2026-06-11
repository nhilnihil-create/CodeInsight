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
using cpp_dec_float_1000 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>>;

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

struct Tmp
{
public:
  Tmp(int N);
};

Tmp::Tmp(int N){}

void solve(void)
{
  int N, M; cin >> N >> M;
  vector<int> S(N), T(M);
  for (auto& s : S) {
    cin >> s;
  }
  for (auto& t : T) {
    cin >> t;
  }

  vector<vector<cpp_int>> dp(N, vector<cpp_int>(M));
  vector<vector<cpp_int>> sum(N, vector<cpp_int>(M));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      auto i0 = i - 1;
      auto j0 = j - 1;
      if (S[i] == T[j]) {
        dp[i][j] += (i0 >= 0 && j0 >= 0) ? sum[i0][j0] : 0;
        dp[i][j] += 1;
        dp[i][j] %= MOD;
      }
      if (i0 >= 0) { sum[i][j] += sum[i0][j]; sum[i][j] %= MOD; }
      if (j0 >= 0) { sum[i][j] += sum[i][j0]; sum[i][j] %= MOD; }
      if (i0 >= 0 && j0 >= 0) { sum[i][j] -= sum[i0][j0]; sum[i][j] = (sum[i][j] + MOD) % MOD; }
      sum[i][j] += dp[i][j];
      sum[i][j] %= MOD;
    }
  }
  cpp_int ans = sum[N-1][M-1] + 1;
  ans %= MOD;
  cout << ans.str() << CRLF;

  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
