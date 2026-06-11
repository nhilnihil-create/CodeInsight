#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n,m;
  cin >> n >> m;
  
  int a[m];
  cin >> a[0];
  for(int i = 1; i < m; i++)
  {
    cin >> a[i];
    if(a[i] == a[i-1]+1)
    {
      cout << 0 << endl;
      return 0;
    }
  }
  
  int f[n+1];
  ll mod = 1000000007;
  f[0] = 1; f[1] = 1;
  for(int i = 2; i <= n; i++)
  {
    f[i] = f[i-1] + f[i-2];
    f[i] %= mod;
  }
  
  ll ans = 1;
  ll now = 0;
  ll up = 0;
  for(int i = 0; i < m; i++)
  {
    up = a[i] - now;
    ans = (ans % mod) * (f[up-1] % mod);
    ans %= mod;
    now = a[i]+1;
  }
  up = n - now;
  ans *= f[up];
  
  ans %= mod;
  cout << ans << endl;

}
  
