bool DBG = false;
//#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using ld = long double;
//using i128 = __int128_t;
//using bint = boost::multiprecision::cpp_int;
//using d1024 = boost::multiprecision::number<mp::cpp_dec_float<1024>>;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=((b)-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define fs first
#define sd second
#define couts(x) cout << (x) << (" ")
#define coutn(x) cout << (x) << ("\n")
//#define ncouts(x) numout(x),outst[outst_N++] = ' '
//#define ncoutn(x) numout(x),outst[outst_N++] = '\n'
//#define scouts(x) strout(x),outst[outst_N++] = ' '
//#define scoutn(x) strout(x),outst[outst_N++] = '\n'
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
#define sorta(x) sort(ALL(x))
#define sortra(x) sort(RALL(x))
#define revall(x) reverse(ALL(x))
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
/*
std::ostream &operator<<(std::ostream &os, const i128 nu){
  i128 co = nu;
  if(co==0){cout << '0';}
  else{
    string ous; if(co<0){cout<<'-'; co*=-1;}
    while(co){
      ous += (co%10)+'0';
      co /= 10;
    }
    reverse(ALL(ous));
    cout<<ous;
  }
  return os;
}
std::istream &operator>>(std::istream &is, i128 &nu){ string cs; cin >> cs; nu=0;int mn=1; for(auto &x:cs) { if(x!='-'){nu*=10;nu+=(x-'0');} else mn *= -1;} nu *= mn;  return is; }

*/


template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;
template<class T> using V3 = V<V2<T>>;
template<class T> using V4 = V<V3<T>>;


constexpr ll LINF = 1LL << 60;
constexpr int IINF = 1 << 28;
constexpr ll mod =  1'000'000'007;
//constexpr ll mod = 998244353;


struct rdm{
  std::random_device rdmdevice;
  std::mt19937_64 mt;
  int option;
  rdm(){
    mt = std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count());
  }
  rdm (int x){
    mt = std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count());
    if(x==1) mt = std::mt19937_64(rdmdevice());
  }
  int uni_i32(int x, int y){
    std::uniform_int_distribution<int> urd(x, y);
    return urd(mt);
  }
  long long int uni_i64(long long x, long long y){
    std::uniform_int_distribution<long long> urd(x, y);
    return urd(mt);
  }
  double uni_d64(double x, double y){
    std::uniform_real_distribution<double> urd(x, y);
    return urd(mt);
  }
};

struct timet{
  std::vector<std::chrono::system_clock::time_point> tp;
  timet(){
    tp = std::vector<std::chrono::system_clock::time_point>(10);
  }
  timet(int n) {
    tp = std::vector<std::chrono::system_clock::time_point>(n);
  }
  void recordtime(int x){
    tp[x] = std::chrono::system_clock::now();
  }
  int caltime(int x, int y, int option = 0){
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp[y] - tp[x]).count();
  }
};


void solve(){
  rdm rds;
  int d; cin >> d;
  V<ll> c(26);V2<ll> s(d,V<ll>(26)); cin >> c >> s;
  V<int> t(d); cin >> t; FOR(i,0,d) t[i]--;
  V<ll> l(26,-1);
  ll ret = 0;
  FOR(i,0,d){
    ret += s[i][ t[i] ];
    l[ t[i] ] = i;
    FOR(j,0,26) ret -= c[ j ]*(i-l[j]);
    
    
    if(i!=d-1)coutn(ret);
    else cout << ret;
  }
  
  
}



int main(void){
  //std::cout << std::fixed << std::setprecision(20);
  cin.tie(0);
  //ios::sync_with_stdio(false);
  solve();
  //printf("%s", outst);
  return 0;
}


