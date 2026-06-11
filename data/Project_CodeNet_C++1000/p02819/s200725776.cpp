#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int x;
  cin >> x;
  int ans = 0;
  while (1)
  {
    int prime = 1;
    for (int i = 2; i * i < x; i++)
    {
      if (x % i == 0)
      {
        prime = 0;
      }
    }
    if (prime)
    {
      ans = x;
      break;
    }
    x++;
  }

  cout << ans << endl;
}
