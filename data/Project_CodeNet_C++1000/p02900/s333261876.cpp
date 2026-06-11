#include <bits/stdc++.h>  // include all standard C++ libraries

using namespace std;

// Loops
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define _rrep(i,n) rrepi(i,n,0)
#define rrepi(i,a,b) for(int i=int(a)-1;i>=int(b);--i)

#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(xi, x) for (auto&& xi : x)
// Note: we can use rep(i,N) or rep(i,from,to)


// typedef
template <class T> using vec = vector<T>;
using ll = long long;
using vi   = vec<int>;
using vvi  = vec<vi>;
using vvvi = vec<vvi>;
using pii  = pair<int, int>;


// Constants

// Shorter repr for frequently used terms
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second


// Algorithms
#define all(x) (x).begin(), (x).end()
#define uniq(v) v.erase( unique(all(v)), v.end() )
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))

template<class T> pair<T, size_t> max(vector<T> &x){ auto it = max_element(all(x)); return mp(*it, it-x.begin()); }
template<class T> pair<T, size_t> min(vector<T> &x){ auto it = min_element(all(x)); return mp(*it, it-x.begin()); }

template<class T> inline bool chmax(T &maxval, const T &newval) { if (maxval<newval) { maxval=newval; return 1; } return 0; }
template<class T> inline bool chmin(T &minval, const T &newval) { if (minval>newval) { minval=newval; return 1; } return 0; }

// Utilities
// Grid world utilities
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
#define inside(H,W,y,x) 0<=(x) && (x)<(W) && 0<=(y) && (y)<(H)

inline int in() {int x; cin >> x; return x;} // read int from cin
inline  ll IN() {ll x; cin >> x; return x;}  // read ll from cin



// Debug
#ifdef LOCAL
  #include "dump.hpp"
  #define debug(x) cerr << #x << ": " << x << '\n'
#else
  #define dump(...)
  #define debug(x)
#endif

// Paste snippets here!!
vector<pair<ll,ll>> prime_factor(ll num){
  vector<pair<ll,ll>> vpl;
  ll cnt;
  for(ll i=2;i*i<=num;i++){
    if(num%i!=0) continue;
    cnt=0;
    while(num%i==0){
      num/=i;
      cnt++;
    }
    vpl.push_back(mp(i,cnt));
  }
  if(num>1) vpl.push_back(make_pair(num,1));
  return vpl;
}
// 

int main(){
  cin.tie(0); ios::sync_with_stdio(false);    // Magic for faster cin
  ll a, b;
  cin >> a >> b;
  auto pa = prime_factor(a);
  auto pb = prime_factor(b);
  unordered_set<int> sa, sb;
  for(auto kv : pa){
    sa.insert(kv.first);
  }
  for(auto kv : pb){
    sb.insert(kv.first);
  }
  int cnt = 1;  // 1 は公約数
  for(auto i : sa){
    if(sb.find(i)!=sb.end()) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
