#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, d;
  cin >> n >> d;
  int ans = n / (2 * d + 1);
  if (n % (2 * d + 1) == 0)
  {
    cout << ans << endl;
  }
  else
  {
    cout << ans + 1 << endl;
  }
}
