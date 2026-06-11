#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, D, A, x, h, ans = 0;
  cin >> N >> D >> A;
  vector<pair<int64_t, int64_t>> xh(N);
  for (int i = 0; i < N; i++)
  {
    cin >> x >> h;
    xh[i] = {x, h};
  }
  sort(xh.begin(), xh.end());
  int64_t total = 0;
  queue<pair<int64_t, int64_t>> Q;
  for (int i = 0; i < N; i++)
  {
    tie(x, h) = xh[i];
    while (Q.size() && Q.front().first < x)
    {
      total -= Q.front().second;
      Q.pop();
    }
    h -= total;
    if (h > 0)
    {
      int64_t n = (h + A - 1) / A;
      ans += n;
      int64_t damage = n * A;
      total += damage;
      Q.emplace(x + 2 * D, damage);
    }
  }
  cout << ans << endl;
}