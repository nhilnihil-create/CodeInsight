#include <bits/stdc++.h>
using i64 = std::int_fast64_t;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

int main() {
  int n; scanf("%d", &n); std::vector<int> a(n);
  for(auto& v: a) scanf("%d", &v);

  std::vector<int> deg(1e6 + 1);
  for(auto v: a) deg[v]++;

  for(int i = (int)deg.size() - 1; i > 0; i--) {
    for(int j = 2 * i; j < deg.size(); j += i) deg[j] += deg[i];
  }

  int ans = 0;
  for(auto v: a) {
    if(deg[v] > 1) continue;

    ans++;
  }

  printf("%d\n", ans);
  return 0;
}
