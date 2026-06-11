#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n, d;
  cin >> n >> d;

  int vec[n][d];

  rep(i, n)
  {
    rep(j, d)
    {
      cin >> vec[i][j];
    }
  }

  int flag = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      double dis = 0;

      for (int k = 0; k < d; k++)
      {
        double dif = vec[i][k] - vec[j][k];
        dis += dif * dif;
      }

      dis = sqrt(dis);
      if (floor(dis) == dis)
        flag++;
    }
  }

  cout << flag;
}
