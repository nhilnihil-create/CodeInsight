bool DBG = false;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using ld = long double;
//using i128 = __int128_t;
//using bint = boost::multiprecision::cpp_int
//using d1024 = boost::multiprecision::number<mp::cpp_dec_float<1024>>;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define fs first
#define sd second
#define couts(x) cout << (x) << (" ")
#define coutn(x) cout << (x) << ("\n")
#define dcouts(x) if(DBG) couts(x)
#define dcoutn(x) if(DBG) coutn(x)
#define endl "\n"
#define psb push_back
#define ppb pop_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define LBIT(x,a) (((x)>>(a))&1LL)
#define IBIT(x,a) (((x)>>(a))&1)
#define BCOUNT(x) (__builtin_popcount(x))
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


template<class T>
V<T> VF(V<T> v, function<T(T)> f){
  int n = (int) v.size();
  V<T> ret(n);
  for(int i=0; i<n; ++i) {
    T a = v[i];
    ret[i] = f(a);
  }
  return ret;
}
template<class T, class U>
V<U> VF2(V<T> v, function<U(T)> f){
  int n = (int) v.size();
  V<U> ret(n);
  for(int i=0; i<n; ++i) {
    T a = v[i];
    ret[i] = f(a);
  }
  return ret;
}
template<class T>
void VFS(V<T> &v, function<T(T)> f){
  int n = (int) v.size();
  for(int i=0; i<n; ++i) {
    T a = v[i];
    v[i] = f(a);
  }
  return;
}









/*

using PLI = pair<ll,int>;
using PLL = pair<ll,ll>;


void solve155f(){
  int n, m; cin >> n >> m;
  V<PLI> ab(n);
  cin >> ab;
  sort( ALL(ab) );
  V<PLL> lr(m);
  cin >> lr;
  V2<int> g(n);
  FOR(i,0,m){
    int l = (int)( lb(ALL(ab), PLI(lr[i].fs, 0) ) - ab.begin() ),
        r = (int)( ub(ALL(ab), PLI(lr[i].sd, 2) ) - ab.begin() );
    lr[i].fs = l, lr[i].sd = r;
    if(l==r) continue;
    g[l].psb(r);
    g[r].psb(l);
  }
}
 
void solve_157f(){
  int n, k; cin >> n >> k;
  
}

*/



constexpr ll LINF = 1LL << 50;
V2<int> g;
V2<ll> dist;

void bfs(int s){
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int p = q.front(); q.pop();
    for(auto x: g[p]){
      bool ud = false;
      FOR(j,0,3){
        if(dist[j][p]>LINF) continue;
        ll a = (dist[j][p]*3+j+1)/3, b = (dist[j][p]*3+j+1)%3;
        if( a<dist[b][x] ) dist[b][x] = a, ud = true;
      }
      if(ud) q.push(x);
    }
  }
}

void solve(){
  int n, m; cin >> n >> m;
  g = V2<int>(n);
  dist = V2<ll>(3, V<ll>(n,LINF+10) );
  FOR(i,0,m){
    int u, v; cin >> u >> v;
    --u, --v;
    g[u].psb(v);
  }
  int s, t; cin >> s >> t; --s, --t;
  dist[0][s] = 0;
  bfs(s);
  if(dist[0][t]>LINF) coutn(-1);
  else coutn(dist[0][t]);
  //coutn(dist);
}
 
int main(void){
  //std::cout << std::fixed << std::setprecision(20);
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

