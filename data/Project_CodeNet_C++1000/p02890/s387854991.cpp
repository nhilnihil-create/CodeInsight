#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) { return std::vector<T>(n, std::forward<T>(val)); }
template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}
template<class Cond> struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  template<class T> bool operator()(T& a, const T& b) const { if(cond(a, b)) { a = b; return true; } return false; }
};
template<class Cond> chain<Cond> make_chain(Cond cond) { return chain<Cond>(cond); }

int main() {
  i64 N;
  cin >> N;
  map<i64, i64> mp;
  rep(i,0,N) {
    i64 a;
    cin >> a;
    mp[a]++;
  }
  map<i64, i64> cnt;
  i64 sum = 0;
  i64 c = 0;
  for(auto p: mp) {
    cnt[p.second]++;
    sum += p.second;
  }
  vector<i64> ans(N + 1);
  auto chmax = make_chain(std::less<i64>());
  for(i64 i = N + 1; i --> 1;) {
    c += cnt[i];
    sum -= cnt[i] * i;
    chmax(ans[(sum + c * i) / i], i);
  }
  for(int i = N; i --> 0;) {
    chmax(ans[i], ans[i + 1]);
  }
  rep(i,1,N + 1) {
    cout << ans[i] << endl;
  }
}
