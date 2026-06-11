#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



ifstream fin ("calafat.in");
ofstream fout ("calafat.out");


ll v[5002], f[5002];
ll n, x, m, ans, k, q;

int main()
{
  cin >> k >> q;
  for (ll i = 0; i < k; i++)
    cin >> v[i];
  while (q--) {
    cin >> n >> x >> m;
    n--;
    x %= m;
    ans = n;
    for (ll j = 0; j < k; j++) {
      f[j + 1] = f[j] + v[j]% m;
      if (!(v[j] %m))
        ans -= (n / k + (j < n % k));
    }
    ans -= (x + f[k] * (n / k) + f[n % k]) / m;
    cout << ans << "\n";
  }
  return 0;
}
