#include <bits/stdc++.h>
using namespace std;

int main()
{
  int M, D, cnt = 0;
  cin >> M >> D;
  for (int m = 1; m <= M; m++)
  {
    for (int d = 1; d <= D; d++)
    {
      int d1 = d % 10;
      int d10 = d / 10;
      if (m == d1 * d10 && d1 >= 2 && d10 >= 2)
        cnt++;
    }
  }
  cout << cnt << endl;
}
