#include <bits/stdc++.h>
using namespace std;
typedef function<bool (int64_t x)> FT;
int64_t f(int64_t i, int64_t e, const FT &g)
  {int64_t m = 0, t = e;
  while (llabs(i - e) > 1) {m = (i + e) / 2; if (g(m)) i = m; else e = m;}
  return g(i) ? i : t;}
int main()
  {string s, t; cin >> s >> t;
  map<char, vector<int>> m;
  for (int i = 0; i < s.size(); ++i) m[s[i]].push_back(i);
  auto i = 0LL, ans = 0LL;
  for (auto c: t)
    {auto &is = m[c];
    if (is.empty()) {puts("-1"); return 0;}
    auto g = [&](int64_t x) {return i <= is[x];};
    auto j = f(is.size() - 1, -1, g);
    if (j == -1)
      {ans += s.size();
      i = 0; i = is[f(is.size() - 1, -1, g)] + 1;}
    else i = is[j] + 1;}
  ans += i; cout << ans << endl;}