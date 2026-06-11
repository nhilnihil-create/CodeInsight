#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t X, Y, A, B, C, a, t, x = 0, y = 0, z = 0, ans = 0;
  cin >> X >> Y >> A >> B >> C;
  priority_queue<pair<int64_t, int64_t>> pq;
  for (int i = 0; i < A; i++)
  {
    cin >> a;
    pq.push({a, 0});
  }
  for (int i = 0; i < B; i++)
  {
    cin >> a;
    pq.push({a, 1});
  }
  for (int i = 0; i < C; i++)
  {
    cin >> a;
    pq.push({a, 2});
  }
  while (x + y + z < X + Y)
  {
    tie(a, t) = pq.top();
    pq.pop();
    if (t == 0 && x < X)
    {
      ans += a;
      x++;
    }
    else if (t == 1 && y < Y)
    {
      ans += a;
      y++;
    }
    else if (t == 2)
    {
      ans += a;
      z++;
    }
  }
  cout << ans << endl;
}