#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define lint long long
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail){
  std::cerr << " " << head;
  debug_impl(tail...);
}
#define debug(...) std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
  debug_impl(__VA_ARGS__);\
  std::cerr << std::noboolalpha;

int main()
{
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  rep(i, 0, n)
  {
    rep(j, i + 1, n)
    {
      auto ret = __builtin_ctz(i ^ j) + 1;
      std::cout << (j > i + 1 ? " " : "") << ret;
    }
    std::cout << std::endl;
  }
  return 0;
}
