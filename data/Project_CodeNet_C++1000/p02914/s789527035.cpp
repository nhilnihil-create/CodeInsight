#define MOD_TYPE 1

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using multiInt = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
*/
/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
//constexpr ll MOD = 1;
constexpr int INF = (int)1e9 + 10;
constexpr ll LINF = (ll)4e18;
constexpr double PI = acos(-1.0);
constexpr double EPS = 1e-10;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

inline void init_main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
template <typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val)
{
  fill((T *)array, (T *)(array + N), val);
}
template <typename T, typename U>
constexpr ostream &operator<<(ostream &os, pair<T, U> &p) noexcept
{
  os << p.first << " " << p.second;
  return os;
}
#pragma endregion

const int MAX_ROW = 110;
const int MAX_COL = 100010;
struct BitMatrix
{
  int H, W;
  bitset<MAX_COL> val[MAX_ROW];
  BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
  inline bitset<MAX_COL> &operator[](int i) { return val[i]; }
};

ostream &operator<<(ostream &s, BitMatrix A)
{
  s << endl;
  for (int i = 0; i < A.H; ++i)
  {
    for (int j = 0; j < A.W; ++j)
    {
      s << A[i][j] << ", ";
    }
    s << endl;
  }
  return s;
}

inline BitMatrix operator*(BitMatrix A, BitMatrix B)
{
  BitMatrix R(A.H, B.W);
  BitMatrix tB(B.W, B.H);
  for (int i = 0; i < tB.H; ++i)
    for (int j = 0; j < tB.W; ++j)
      tB[i][j] = B[j][i];
  for (int i = 0; i < R.H; ++i)
    for (int j = 0; j < R.W; ++j)
      R[i][j] = ((A[i] & tB[j]).count() & 1);
  return R;
}

inline BitMatrix pow(BitMatrix A, long long n)
{
  BitMatrix R(A.H, A.H);
  for (int i = 0; i < A.H; ++i)
    R[i][i] = 1;
  while (n > 0)
  {
    if (n & 1)
      R = R * A;
    A = A * A;
    n >>= 1;
  }
  return R;
}

void GaussJordan(BitMatrix &A, bool is_extended)
{
  vector<bool> used(A.H, false);
  for (int col = 0; col < A.W; ++col)
  {
    if (is_extended && col == A.W - 1)
      break;
    int pivot = -1;
    for (int row = A.H - 1; row >= 0; --row)
    {
      if (used[row])
        continue;
      if (A[row][col])
      {
        pivot = row;
        break;
      }
    }
    if (pivot == -1)
      continue;
    used[pivot] = true;
    for (int row = 0; row < A.H; ++row)
    {
      if (row != pivot && A[row][col])
        A[row] ^= A[pivot];
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  BitMatrix B(60, n + 1);
  ll ans = 0;
  vector<bool> pass(60, false);
  rep(j, 60)
  {
    ll cnt = 0;
    rep(i, n)
    {
      if ((1LL << j) & a[i])
        cnt++;
    }
    if (cnt & 1)
    {
      ans += 1LL << j;
      pass[j] = true;
      continue;
    }
    else if (cnt == 0)
    {
      pass[j] = true;
      continue;
    }
    rep(i, n)
    {
      B[j][i] = (1LL << j) & a[i];
    }
    B[j][n] = 1;
  }
  //dbg(ans);
  //cout << B << endl;
  GaussJordan(B, true);
  //cout << B << endl;
  rep(j, 60)
  {
    if (pass[j])
      continue;
    bool valid = false;
    rep(i, n)
    {
      if (B[j][i])
      {
        valid = true;
        break;
      }
    }
    if (!B[j][n])
      valid = true;
    if (!valid)
      continue;
    ans += (1LL << (j + 1));
  }
  cout << ans << "\n";
}

int main()
{
  init_main();

  solve();

  return 0;
}
