#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using vi = vector<int>;

#define in(v) v; cin >> v;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}

#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

// debug
template<class T>ostream& operator<<(ostream& os,const vector<T>& vec){os<<"{";for(size_t i=0;i<vec.size();++i)os<<(i?", ":"")<<vec[i];os<<"}";return os;}
ostream& operator<<(ostream& os,const vector<char>&v){for(size_t i=0;i<v.size();++i)os<<v[i];return os;}
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>& rhs){os<<"("<<rhs.first<<", "<<rhs.second<<")";return os;}

#ifdef LOCAL
void debug() {cerr << "\n";}
template<class First> void debug(const First& first) {cerr<<first<<"\n";}
template<class First, class... Rest> void debug(const First& first, const Rest&... rest) {cerr<<first<<",";debug(rest...);}
void debug2() {cerr << "\n";}
template<class First> void debug2(const First& first) {cerr<<first<<" ";}
template<class First, class... Rest> void debug2(const First& first, const Rest&... rest) {cerr<<first<<" ";debug2(rest...);}
#else
#define debug(...) 42
#define debug2(...) 42
#endif

template<class T>using vv = vector<vector<T>>;

char s[100][100];
int H, W;

int dp[100][100];
int dfs(int i, int j) {
  if (i == H-1 && j == W-1)
    return s[i][j] == '#';

  if (dp[i][j] != -1)
    return dp[i][j];

  int ans = 10000;
  if (i < H-1)
    ans = min(ans, dfs(i+1, j) + (s[i][j] != s[i+1][j]));
  if (j < W-1)
    ans = min(ans, dfs(i, j+1) + (s[i][j] != s[i][j+1]));
  return dp[i][j] = ans;
}

int main() {
  ins(H, W);

  rep(i, H) rep(j, W) {
    cin >> s[i][j];
    dp[i][j] = -1;
  }

  cout << dfs(0, 0)/2 + (s[0][0] == '#')<< endl;

  return 0;
}
