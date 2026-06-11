#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define fs first
#define sd second
#define couts(x) cout << (x) << (" ")
#define coutn(x) cout << (x) << ("\n")
#define endl "\n"

template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T1, typename T2> std::istream &operator>>(std::istream &is, std::pair<T1,T2> &p){is >> p.first >> p.second; return is; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::deque<T> &vec){ os << "deque["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }

template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;
template<class T> using V3 = V<V2<T>>;
using P = pair<int,int>;

V2<int> ids;
V2<int> g;
V<int> state;
V<int> dp;

static int getid(int x, int y){
  if(x>y) swap(x,y);
  return ids[x][y];
}



int dfs(int s){
  if( (state[s]&1) ){
    if( !( (state[s]>>1) &1 ) ) return -1;
    return dp[s];
  }
  state[s] |= 1;
  if(dp[s]==0) dp[s] = 1;
  for(auto x: g[s]){
    int tmp = dfs(x);
    if(tmp == -1 ) return -1;
    dp[s] = max(dp[s], dp[x] + 1);
  }
  state[s] |= 2;
  return dp[s];
}



void solve(){
  int n; cin >> n;
  V2<int> a(n, V<int>(n-1) );
  cin >> a;
  FOR(i,0,n) {FOR(j,0,n-1) a[i][j]--;}
  ids = V2<int>(n,V<int>(n,0));
  {
    int id = 0;
    FOR(i,0,n){
      FOR(j,i+1,n){
        ids[i][j] = id;
        ++id;
      }
  }}
  g = V2<int>(n*(n-1)/2+5);
  FOR(i,0,n){
    FOR(j,0,n-2){
      g[ getid(i,a[i][j]) ].push_back( getid(i,a[i][j+1]) );
    }
  }
  int ans = 0;
  dp = V<int>(n*(n-1)/2 + 10, 0);
  state = V<int>(n*(n-1)/2 + 10, 0);
  FOR(i,0,n){
    int tmp = dfs(  getid(i,a[i][0]) );
    if(tmp == -1) { couts(-1); return;}
    ans = max(ans, tmp);
  }
  couts(ans);
}

int main(){
  solve();
  return 0;
}