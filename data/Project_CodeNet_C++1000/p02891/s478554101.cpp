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
  string s; cin >> s;
  ll n; cin >> n;
  ll ans = 0;
  ll cnt = 0;
  ll ft = 0;
  ll h = 0;

  int i = 0;
  for(h = 1 ; s[h] == s[0]; h++) ;
  if(h == s.size()) {
    cout << ( n * s.size() / 2 ) << endl;
    return;
  }
  i = 0;
  while(i < s.size()) {
    int j;
    for(j = 1; s[i] == s[i + j]; j++);
    cnt += j / 2;
    i += j;
  }
  int k;
  for(k = 1; s[s.size()-1-k] == s[s.size()-1]; k++);
  
  ans = cnt * n - (s[0] == s[s.size()-1] ? ( h / 2 + k / 2 - (h + k) / 2) * (n - 1): 0);
  
  cout << ans << endl;
}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
