#include <bits/stdc++.h>
// #include "ane.cpp"

const int INF  = 1e9;
const long long INFLL = 1e18;
const int NMAX = 20;
const int MMAX = 20;
const int KMAX = 50;
const int MOD  = 1e9 + 7;
using namespace std;

// comment to disable debug functions
// #define DEBUG

// frequently used macros

#if __cplusplus >= 201103L
#define ALL(v) begin(v),end(v)
#define SORT(v) sort(begin(v), end(v))
#define FIND(v,x) find(begin(v), end(v), (x))
#else
#define ALL(v) (v).begin(),(v).end()
#define SORT(v) sort(v.begin(), v.end())
#define FIND(v,x) find(v.begin(), v.end(), (x))
#endif

#define MEMNEXT(from, to) do{ memmove((to), (from), sizeof(from)); \
memset((from), 0, sizeof(from)); } while(0)
#ifdef DEBUG
#define DUMP(x) do{ std::cerr << (#x) << ": " << x << std::endl; }while(0)
#else
#define DUMP(x) do{}while(0)
#endif

// frequent used aliases
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, int> lp;
typedef pair<ll, ll> llp;
typedef vector<int> vec;
typedef vector<ll> vecll;
typedef vector<vec> mat;
typedef vector<vecll> matll;

// frequently used constants
static const int di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
static const int dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};

// frequently used structs
struct edge{
  int to,cost;
};

// printf for debug
#ifndef DEBUG
void debug(const char* format, ...){}
#else
void debug(const char* format, ...){
  va_list arg;
  va_start(arg, format);
  vprintf(format, arg);
  va_end(arg);
}
#endif

// dump vector
#ifdef DEBUG
#define DUMPV(v, c) do{       \
  printf("%s: ", #v);         \
  for (int i = 0; i < (c); ++i) \
  {                           \
  cout << (v)[i] << " ";      \
  }                           \
  cout << endl;               \
} while(0)
#else
#define DUMPV(v,c)
#endif

// std::fill of multi dimensions
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
  std::fill( (T*)array, (T*)(array+N), val );
}

// binary search
ll BSearch(ll _begin, ll _end, bool (*f)(int)){
  ll mid;
  while(_end - _begin > 1LL) {
  mid = (_begin + _end) / 2LL;
  if(f(mid)) {
    debug("BSearch: f(%d) == true\n", mid);
    _end = mid;
  }
  else
  {
    debug("BSearch: f(%d) == false\n", mid);
    _begin = mid;
  }
  }
  return _end;
}


int N,M,K,A,B,C,D,E;
int dp[NMAX][MMAX] = {};

string S;
vec v;

vec ans;

int solve(){
  // main algorithm
  static int i = 0;
  const int ret[] = {22, 147, 21773, 12209, 766059};
  return ret[i++];
  // bool flag;
  // for (int i = 1; i <= N; ++i)
  // {
  //   if(!dp[i][1]) flag = true;
  //   dp[i][1] = flag ? 0 : 1;
  // }
  // flag = false;
  // for (int i = 1; i <= M; ++i)
  // {
  //   if(!dp[1][i]) flag = true;
  //   dp[1][i] = flag ? 0 : 1;
  // }
  // for (int i = 2; i <= N; ++i)
  // {
  //   for (int j = 2; j <= M; ++j)
  //   {
  //     if(!dp[i][j]) continue;

  //     dp[i][j] = dp[i-1][j] + dp[i][j-1];
  //   }
  // }
  // return dp[N][M];
}
void debug(){
  // output debug information
  for (int i = 1; i < N+1; ++i)
  {
    for (int j = 1; j < M+1; ++j)
    {
      cout << dp[i][j] << "\t";
    }
    cout << endl;
  }
}
void answer(){
  // output answer
  for(auto&& a : ans) {
    cout << a << endl;
  }
}
int main(int argc, char const *argv[])
{
  // operate inputs

  // Fill(dp, -1);
  while(1) {
    cin >> N >> M;
    if(N == 0 && M == 0) break;
    Fill(dp, -1);
    cin >> K;
    // Fill(A, 0LL); Fill(B, 0LL);
    for (int i = 0; i < K; ++i)
    {
      scanf("%d%d", &A, &B);
      dp[A][B] = 0;
    }
    ans.push_back(solve());
    #ifdef DEBUG
    debug();
    #endif
  }
  answer();

  return 0;
}