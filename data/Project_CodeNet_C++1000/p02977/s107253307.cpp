#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

template<typename F>
static inline constexpr decltype(auto) fix(F&& f) noexcept {
  return [f = std::forward<F>(f)](auto&&... args) {
    return f(f, std::forward<decltype(args)>(args)...);
  };
}

int main() {
  const i64 N = [](){ i64 n; cin >> n; return n; }();
  if(__builtin_popcount(N) == 1) {
    cout << "No" << endl;
    return 0;
  }
  
  cout << "Yes" << endl;

  const auto ans = [N](){
    vector<pair<i64, i64>> vec;
    auto dsh = [N](const i64 i) { return i + N; };
    i64 i = 2;
    vec.push_back({1, 2});
    for(;i + 1 <= N;i += 2) {
      vec.push_back({i, i + 1});
      vec.push_back({i + 1, dsh(1)});
      vec.push_back({dsh(1), dsh(i)});
      vec.push_back({dsh(i), dsh(i + 1)});
    }
    if(i == N) {
      const i64 a = i - 2;
      const i64 b = i ^ a ^ 1;
      vec.push_back({i, dsh(a)});
      vec.push_back({dsh(i), b});
    }
    return std::move(vec);
  }();

  for(auto&& p: ans) {
    cout << p.first << " " << p.second << endl;
  }
}
