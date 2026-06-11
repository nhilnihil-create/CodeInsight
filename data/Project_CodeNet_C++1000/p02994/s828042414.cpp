#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, l;
  cin >> n >> l;
  int ans = 0;
  int taste = 1000000007;
  for (int i = 1; i <= n; i++)
  {
    ans += l + i - 1;
    taste = min(taste, abs(0 - (l + i - 1)));
  }
  if (ans > 0)
  {
    cout << ans - taste << endl;
  }
  else
  {
    cout << ans + taste << endl;
  }
}
