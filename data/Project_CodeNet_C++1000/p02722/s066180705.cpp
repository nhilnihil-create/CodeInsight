#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  ll n;
  cin >> n;
  int ans = 0;
  for(ll i = 1; i*i <= n-1; i++){
    if((n-1) % i != 0) continue;
    ll j = (n-1) / i;
    if(i == 1 && i == j) continue;
    if(i == 1 || i == j) ans++;
    else ans += 2;
  }
  for(ll i = 1; i*i <= n; i++){
    if(n % i != 0) continue;
    ll nn = n;
    ll j = n / i;
    while(nn % j == 0 && nn > 1) nn /= j;
    if(nn % j == 1) ans++;
    if(i == 1 || i == j) continue;
    nn = n;
    while(nn % i == 0 && nn > 1) nn /= i;
    if(nn % i == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}