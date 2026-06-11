#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//ll s[500500];
//const int N=1e7+5;
//ll f[N],n,ans;
int main(){
   ll n;
  cin >> n;
  ll ans = n - 1;
  for (ll i = 1; i * i <= n; i++) {
    if (n%i)continue;
    ll j = n / i;
    ans = min(ans, i + j - 2);
  }
  cout << ans << "\n";
}


