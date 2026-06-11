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

int main(void)
{
  ll n, k; cin >> n >> k;
  ll ans = 0;
  if(k == 1) {
    ans = 0;
  } else {
    ans = n - k;
  }
  cout << ans << endl;
}
