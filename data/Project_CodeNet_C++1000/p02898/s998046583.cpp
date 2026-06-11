#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int h;
    cin >> h;

    if (k <= h)
    {
      ans++;
    }
  }
  cout << ans << endl;
}
