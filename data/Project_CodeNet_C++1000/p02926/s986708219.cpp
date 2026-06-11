#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) noexcept {
  return std::vector<T>(n, std::forward<T>(val));
}

template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) noexcept {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}

template<class T, class Cond>
struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  bool operator()(T& a, const T& b) const {
    if(cond(a, b)) { a = b; return true; }
    return false;
  }
};
template<class T, class Cond>
chain<T, Cond> make_chain(Cond cond) { return chain<T, Cond>(cond); }

int main() {
  i64 N;
  cin >> N;
  vector<double> X(N), Y(N);
  vector<pair<double, i64>> vec(N);
  rep(i,0,N) {
    cin >> X[i] >> Y[i];
    vec[i].first = std::atan2(Y[i], X[i]);
    vec[i].second = i;
  }
  double ans = 0;
  sort(all(vec));
  rep(i,0,N) {
    rep(j,1,N + 1) {
      double dx = 0;
      double dy = 0;
      rep(k,i,i + j) {
        dx += X[vec[k % N].second];
        dy += Y[vec[k % N].second];
      }
      double res = std::sqrt(dx * dx + dy * dy);
      ans = std::max(ans, res);
    }
  }             
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
