#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

int main()
{
  string l;
  cin >> l;
  vector<ll> pow3(l.size());
  int s = l.size();
  rep(i, s)
    if (i == 0)
      pow3[0] = 1;
    else
      pow3[i] = pow3[i-1] * 3 % MOD;
  ll ans = 0;
  ll c = 1;
  for (char i : l)
  {
    s--;
    if (i == '1')
    {
      ans = (ans + c * pow3[s]) % MOD;
      c = c * 2 % MOD;
    }
  }
  ans = (ans + c) % MOD;
  cout << ans << endl;
  return 0;
}