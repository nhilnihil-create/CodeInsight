#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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
#define rrep(i,n) for(long long i=(n);i>=0;--i)
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

int main() {
  string T;
  ins(T);

  stack<char> st;
  rrep(i, T.size()-1) {
    if (T[i] != '?')
      st.push(T[i]);
    else {
      st.push('D');
    }
  }
  while (!st.empty()) {
    cout << st.top(); st.pop();
  }
  cout << endl;


  return 0;
}
