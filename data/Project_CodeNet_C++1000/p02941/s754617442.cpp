#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_geneous = 0; ngtkana_is_geneous < n; ngtkana_is_geneous++)
#define rep(i, begin, end) for(int i = begin; i < end; i++)

int main()
{
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  std::queue<int> que;
  rep(i, 0, n)
  {
    que.emplace(i);
  }
  long long ret = 0;
  while (!que.empty())
  {
    auto crr = que.front(); que.pop();
    auto prv = (crr - 1 + n) % n;
    auto nxt = (crr + 1)     % n;
    auto div = b.at(prv) + b.at(nxt);
    auto dif = b.at(crr) - a.at(crr);
    if (div <= dif)
    {
      auto q = dif / div;
      ret += q;
      b.at(crr) -= q * div;
      que.emplace(prv);
      que.emplace(nxt);
    }
  }
  if (a != b)
  {
    std::cout << -1 << std::endl;
    return 0;
  }
  std::cout << ret << std::endl;
  return 0;
}
