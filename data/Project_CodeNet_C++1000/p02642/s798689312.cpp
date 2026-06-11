#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  const int m = 1000002;
  int n, t, ans = 0;
  cin >> n;
  vector<bool> a(m, false);
  vector<int> b(n);
  rep(i, n)
  {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  rep(i, n - 1)
  {
    if (a[b[i]] == true)
      continue;
    if (b[i] == b[i + 1])
    {
      a[b[i]] = true;
    }
    for (int j = 2; j < b[n - 1] / b[i] + 1; j++)
    {
      a[j * b[i]] = true;
    }
  }
  rep(i, n)
  {
    if (a[b[i]] == false)
      ans++;
  }
  cout << ans;
}
