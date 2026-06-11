#include <bits/stdc++.h>
using namespace std;

int main()
{
  int		n, count = 0;
  double	sq;
  
  cin >> n;
  for (int c = 1; c < n; c++)
  {
    sq = sqrt((double(n - c)));
    if ((int)sq * (int)sq == n - c)
      count++;
    for (int a = 1; a < sq; a++)
    {
      if (((n - c) % a) == 0)
        count += 2;
    }
  }
  cout << count << endl;
  return (0);
}