#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++)
  {
    cin >> b[i];
  }
  vector<int> a(n);
  a[n - 1] = b[n - 2];
  a[0] = b[0];
  for (int i = 1; i < n - 1; i++)
  {
    a[i] = min(b[i], b[i - 1]);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += a[i];
  }
  cout << ans << endl;
}
