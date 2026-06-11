#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

void solve()
{
  ll x; cin >> x;
  ll k1, k2;
  bool ok = false;
  k1 = x / 100;
  k2 = x / 105;
  //  cout << k2 << " - " << k1 << endl;
  for(ll i = k2; i <= k1; i++) {
    //cout << i * 100 << " - " << i * 105 << endl;
    if(i * 100 <= x && x <= i * 105) ok = true;
  }
  cout << (ok?"1":"0") << endl;
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
