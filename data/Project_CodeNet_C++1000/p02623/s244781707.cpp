#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> cs_a(n + 1, 0), cs_b(m + 1, 0);
  rep(i, n)
  {
    int a;
    cin >> a;
    cs_a[i+1] = cs_a[i] + a;
  }
  rep(i, m)
  {
    int b;
    cin >> b;
    cs_b[i+1] = cs_b[i] + b;
  }
  int ans = 0;
  rep(i, n + 1)
  {
    if (cs_a[i] > k)
      break;
    int l = 0;
    int r = m + 1;
    while (l + 1 < r)
    {
      int mid = (l + r) / 2;
      if (cs_b[mid] <= k - cs_a[i])
        l = mid;
      else
        r = mid;
    }
    ans = max(ans, i + l);
  }
  cout << ans << endl;
  return 0;
}