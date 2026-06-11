#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a, x, y, ans = 0;
  cin >> N;
  vector<vector<pair<int64_t, int64_t>>> vp(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    for (int j = 0; j < a; j++)
    {
      cin >> x >> y;
      x--;
      vp[i].push_back({x, y});
    }
  }
  for (int bit = 0; bit < (1 << N); bit++)
  {
    bool ok = 1;
    for (int i = 0; i < N; i++)
    {
      if (!(bit & (1 << i)))
        continue;
      for (auto p : vp[i])
      {
        tie(x, y) = p;
        if (y == 1 && (!(bit & (1 << x))))
          ok = 0;
        else if (y == 0 && (bit & (1 << x)))
          ok = 0;
      }
    }
    if (ok)
    {
      ans = max(ans, (int64_t)__builtin_popcount(bit));
    }
  }
  cout << ans << endl;
}
