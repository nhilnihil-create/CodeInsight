#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  a.push_back(k + a[0]);
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    len = max(len, a[i + 1] - a[i]);
  }
  int ans = k - len;
  cout << ans << endl;
}
