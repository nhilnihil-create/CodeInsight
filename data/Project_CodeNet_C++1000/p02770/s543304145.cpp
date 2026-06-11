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



void solve(){
  int k, q; cin >> k >> q;
  V<ll> d(k); cin >> d;
  {
  int _01_ = q;
  do{
    int n, x, m; cin >> n >> x >> m; --n;
    ll ans = 0, xn = x % m, c = n/k + 1 ;
    V<ll> dm(k);
    IFOR(i,0,k) dm[i] = d[i] % m;
    FOR(i,0,(n)%k){
      xn += c*dm[i];
      if( dm[i]==0 ) ans += c;
    }
    --c;
    FOR(i,(n)%k,k){
      xn += c*dm[i];
      if( dm[i]==0 ) ans += c;
    }
    ans += xn / m;
    ans= n - ans;
    coutn(ans);
  }while(--_01_);
  }
}
 
 
 
int main(void){
  //std::cout << std::fixed << std::setprecision(20);
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

