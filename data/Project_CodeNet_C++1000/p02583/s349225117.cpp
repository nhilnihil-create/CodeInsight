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

#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(int i=0,_i=(n);i<_i;++i)
#define _rep3(i,a,b) for(int i=(a),_i=(b),_ii=(b)>(a)?1:-1;abs(_i-i)>0;i+=_ii)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define rrep(i,n) for(long long i=(n);i>=0;--i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

// === debug ===
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
// === end ===

int main() {
  int N;
  ins(N);

  vector<ll> L(N);
  rep(i, N) {
    cin >> L[i];
  }

  int count = 0;
  rep(i, N) rep(j, i+1, N) rep(k, j+1, N) {
    if (L[i] == L[j] || L[i] == L[k] || L[j] == L[k])
      continue;
    ll z = max(L[i], max(L[j], L[k]));
    if (2 * z < L[i] + L[j] + L[k]) {
      ++count;
    }
  }
  cout << count << endl;

  return 0;
}
