#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

  ll k;
  cin >> k;
  ll ans = 0;
  ll total = 0;
  ll q = 7;
  while(ans < k+5){
    ans ++;
    total += q;
    total %= k;
    if (total==0){
      cout << ans << endl;
      return 0;
    }

    q *= 10;
    q %= k;
  }

  cout << -1 << endl;

  return 0;
}