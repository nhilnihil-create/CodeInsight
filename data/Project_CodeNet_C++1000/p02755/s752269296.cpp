#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;
  int ans = -1;
  for (int i = 1; i <= 1250; i++)
  {
    if (floor(i * 0.08) == a && floor(i * 0.1) == b)
    {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
