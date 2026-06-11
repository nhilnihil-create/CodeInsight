#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  ll n, k;  cin >> n  >> k;
  vector<ll> a(n);

  for(int i=0; i<n; i++)  cin >> a.at(i);
  ll rc=0, lc=0, ans=0;
  for(int i=0; i<n; i++){
    rc=0, lc=0;
    for(int j=i; j<n; j++){
      if(a[i]>a[j]) rc += 1;
      rc %= MOD;
    }
    for(int j=0; j<n; j++){
      if(a[i]<a[j]) lc += 1;
      lc %= MOD;
    }
    ans += rc*k%MOD;
    ans += k*(k-1)/2%MOD*lc%MOD;
    ans %= MOD;
  }
  // for(int i=n-1; 0<=i; i--){
  //   for(int j=n-1; 0<=j; j--)
  //     if(a[j]>a[i]) lc += 1;
  //     lc %= MOD;
  // }
  // ll ans, buff=(k+1)*k/2%MOD, bet=
  // ans = rc*buff%MOD + lc*bet%MOD;

  cout << ans << endl;
}
