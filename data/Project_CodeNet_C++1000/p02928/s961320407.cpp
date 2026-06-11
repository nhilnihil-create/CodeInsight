#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(k,i,n) for(ll i=k;i<n;++i)

int main() {
  int n;
  ll k,ans = 0,mod = 1000000000+7;
  cin >> n >> k;
  vector<int>a(n);
  for(int i = 0;i < n;i++) cin >> a[i];
  for(int i = 0;i < n;i++){
    ll p = 0,b = 0;
    rep(i+1,j,n)if(a[i]>a[j])b++;
    rep(0,j,n)if(a[i]>a[j])p++;
    ans+=b*k%mod;
    ans%=mod;
    ans+=k*(k-1)/2%mod*p%mod;
    ans%=mod;
  }
  cout << ans << endl;
}