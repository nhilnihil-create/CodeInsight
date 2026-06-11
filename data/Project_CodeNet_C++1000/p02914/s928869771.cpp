#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

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

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

typedef boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1000>> cpp_dec_float_1000;

constexpr char CRLF = '\n';
constexpr char SPACE = ' ';
constexpr char VECTOR_COUT_SEPARATOR = SPACE;
constexpr ll INF = 1000'000'007;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> std::ostream& operator<< (std::ostream& os, const std::vector<T>& vc) { for(auto it = vc.begin(); it != vc.end(); ++it) { if (std::next(it) == vc.end()) os << *it; else os << *it << VECTOR_COUT_SEPARATOR; } return os; }
template<class T1, class T2> inline std::ostream & operator<< (std::ostream & os, const std::pair<T1, T2> & p) { return os << p.first << ' ' << p.second; }

void solve(void)
{
  ui N; cin >> N;
  vector<ull> A(N);
  for(auto& a : A) cin >> a;

  // Aのxor和S0を求める
  auto XOR = [](ull a, ull b){ return a ^ b; };
  auto S0 = boost::accumulate(A, (ull)0, XOR);

  // ビット列S0のうちビット1の桁は題意の組み分けに依存せず決定される
  // 各A_iに対して、S0でビット0の桁を0にする
  for(auto& a : A){
    a &= ~S0;
  }

  // ビット列を行列と見立てて標準化を行う
  for(size_t i = 0; i < A.size(); ++i){
    for (int m_bit = 60; m_bit >= 0; --m_bit){
      // 各A_iの最上位桁を導出
      if(A[i] & (ull)1 << m_bit){
        // 他の各項のm_bit桁目を0にする
        for(size_t k = 0; k < A.size(); ++k)
        {
          if(i == k)
            continue;
          if(A[k] & (ull)1 << m_bit){
            A[k] ^= A[i];
          }
        }
        break;
      }
    }
  }

  // 標準化したAのxor和が題意の要求を満たす
  auto S1 = boost::accumulate(A, (ull)0, XOR);
  // 初めに下したビットを立てる
  auto S2 = S1 | S0;

  auto ans = S1 + S2;
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
