#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)
    cin >> a[i];
  vector<ll> c(60);
  rep(i, n)
    rep(j, 60)
      if ((a[i]>>j & 1) == 1)
        c[j]++;
  ll ans = 0;
  ll d = 1;
  rep(i, 60)
  {
    ans = (ans + c[i] * (n - c[i]) % MOD * d % MOD) % MOD;
    d = (d << 1) % MOD;
  }
  cout << ans << endl;
  return 0;
}