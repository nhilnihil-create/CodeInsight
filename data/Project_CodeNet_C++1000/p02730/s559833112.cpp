#include <bits/stdc++.h>
using namespace std;

//type
#define ll long long
typedef pair<int, int> P;
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007    //10^9+7:合同式の法
#define MAXR 100000       //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first      //pairの一つ目の要素
#define S second     //pairの二つ目の要素
#define Z class
// OTHER
// xの二乗を返す (関数テンプレート版)
template <typename T>
T square(T x) { return x * x; }
template <class T>
T GCD(T a, T b)
{
  T r;
  while (a)
    r = b, b = a, a = r % a;
  return b;
}
template <class T>
T LCM(T a, T b) { return a / GCD(a, b) * b; }

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))
// loop
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (b); i--)
#define FORA(i, I) for (const auto &i : I)

// vector
#define ALL(x) x.begin(), x.end()
#define VEC(type, c, n)   \
  std::vector<type> c(n); \
  for (auto &i : c)       \
    std::cin >> i;

// input
#define INIT                        \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(0);
#define VAR(type, ...) \
  type __VA_ARGS__;    \
  MACRO_VAR_Scan(__VA_ARGS__);
template <typename T>
void MACRO_VAR_Scan(T &t)
{
  std::cin >> t;
}
template <typename First, typename... Rest>
void MACRO_VAR_Scan(First &first, Rest &... rest)
{
  std::cin >> first;
  MACRO_VAR_Scan(rest...);
}
#define VEC_ROW(type, n, ...)            \
  std::vector<type> __VA_ARGS__;         \
  MACRO_VEC_ROW_Init(n, __VA_ARGS__);    \
  for (int w_ = 0; w_ < n; ++w_)         \
  {                                      \
    MACRO_VEC_ROW_Scan(w_, __VA_ARGS__); \
  }
template <typename T>
void MACRO_VEC_ROW_Init(int n, T &t)
{
  t.resize(n);
}
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Init(int n, First &first, Rest &... rest)
{
  first.resize(n);
  MACRO_VEC_ROW_Init(n, rest...);
}
template <typename T>
void MACRO_VEC_ROW_Scan(int p, T &t) { std::cin >> t[p]; }
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Scan(int p, First &first, Rest &... rest)
{
  std::cin >> first[p];
  MACRO_VEC_ROW_Scan(p, rest...);
}

// output
template <typename T>
void MACRO_OUT(const T t) { std::cout << t; }
template <typename First, typename... Rest>
void MACRO_OUT(const First first, const Rest... rest)
{
  std::cout << first << " ";
  MACRO_OUT(rest...);
}
#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define SP std::cout << " ";
#define TAB std::cout << "\t";
#define BR std::cout << "\n";
#define ENDL std::cout << std::endl;

#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n", (x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define ln cout << '\n'
template <Z A>
void pr(A a)
{
  cout << a;
  ln;
}
template <Z A, Z B>
void pr(A a, B b)
{
  cout << a << ' ';
}

int ans = 0;
bool check = 0;
string s, t;
int N = 3;
vector<int> v(N);
int a, b, c, d, n;
int x, y;
int sum;
char ch;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
{

  INIT;

  // VAR(int, n, k, m);
  // VEC(int, a, n - 1);
  cin >> s;
  n = s.length();
  int half = n / 2;

  rep(i, half)
  {
    if (s[i] != s[half - 1 - i])
    {
      No();
      return 0;
    }
  }

  for (int i = half; i < n; i++)
  {
    if (s[i] != s[n - i - 1])
    {
      No();
      return 0;
    }
  }
  Yes();
  return 0;
}
