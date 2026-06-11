#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n, d, a, ans = 0;
  cin >> n >> d >> a;
  vector<pair<int64_t, int64_t>> xh(n);
  for (int i = 0; i < n; i++)
  {
    cin >> xh[i].first >> xh[i].second;
  }
  sort(xh.begin(), xh.end());
  int64_t add = 0;
  queue<pair<int64_t, int64_t>> Q;
  for (int i = 0; i < n; i++)
  {
    int64_t x, h;
    tie(x, h) = xh.at(i);
    if (Q.size())
    {
      while (Q.size() && Q.front().first < x)
      {
        add -= Q.front().second;
        Q.pop();
      }
    }
    h -= add;
    if (h <= 0)
    {
      continue;
    }
    int64_t cnt = (h + a - 1) / a;
    ans += cnt;
    add += a * cnt;
    Q.emplace(x + 2 * d, a * cnt);
  }
  cout << ans << endl;
}