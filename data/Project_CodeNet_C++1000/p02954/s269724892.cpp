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
  ll n; n = s.size();
  vector<ll> cnt(n);
  vector<ll> rsw(n);
  char oldc = 'x';
  ll rc = 0;
  ll lc = 0;
  REP(i, n) {
    if(s[i] == 'R') {
      rc ++;
      rsw[i] = rc;
    } else {
      rc = 0;
    }

    if(s[n-1-i] == 'L') {
      lc ++;
      rsw[n-1-i] = lc;
    } else {
      lc = 0;
    }
  }
  
  REP(i, n) {
   // cout << rsw [i] << " " ;
    cnt[i] = 0;
  }
  cout << endl;

  REP(i, n-1) {
    if(s[i] == 'R' && s[i + 1] == 'L') {
      cnt[i] = rsw[i] / 2 + rsw[i] % 2 + rsw[i + 1] / 2;
      cnt[i + 1] = rsw[i] / 2 + rsw[i + 1] / 2 + rsw[i + 1] % 2;
    }
  }

  REP(i, n) {
    cout << cnt[i] << " " ;
  }
  cout << endl;
  

}


int main(void)
{
  // ll t; cin >> t; REP(i, t)
  solve();
}
