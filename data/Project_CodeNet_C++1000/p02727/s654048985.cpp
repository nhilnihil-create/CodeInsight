#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t X, Y, A, B, C, p, q, r;
  cin >> X >> Y >> A >> B >> C;
  priority_queue<int64_t> P, Q, R;
  for (int i = 0; i < A; i++)
  {
    cin >> p;
    P.push(p);
  }
  for (int i = 0; i < B; i++)
  {
    cin >> q;
    Q.push(q);
  }
  for (int i = 0; i < C; i++)
  {
    cin >> r;
    R.push(r);
  }
  int64_t x = 0, y = 0, z = 0, ans = 0;
  while (x + y + z < X + Y)
  {
    int64_t pf = -1, qf = -1, rf = -1;
    if (!P.empty())
      pf = P.top();
    if (!Q.empty())
      qf = Q.top();
    if (!R.empty())
      rf = R.top();
    if (pf >= qf && pf >= rf && x < X)
    {
      ans += pf;
      P.pop();
      x++;
    }
    else if (qf >= pf && qf >= rf && y < Y)
    {
      ans += qf;
      Q.pop();
      y++;
    }
    else
    {
      ans += rf;
      R.pop();
      z++;
    }
    if (x == X)
    {
      while (!P.empty())
        P.pop();
    }
    if (y == Y)
    {
      while (!Q.empty())
        Q.pop();
    }
  }
  cout << ans << endl;
}