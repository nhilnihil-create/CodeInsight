#include <bits/stdc++.h>
using namespace std;

long n,k,ans=0,mod=1000000007;

long modpow(long modpow_x,long modpow_y) {
  long modpow_return=1;
  for(long i=1;i<=modpow_y;i*=2) {
    if(modpow_y/i%2==1) modpow_return=modpow_return*modpow_x%mod;
    modpow_x=modpow_x*modpow_x%mod;
  }
  return modpow_return;
}

int main() {
  cin >> n >> k;
  vector<long> a(k);
  for(long i=k;i>0;i--) {
    a[i-1]=modpow(k/i,n);
  }
  for(long i=k;i>0;i--) {
    for(long j=i*2;j<=k;j+=i) {
      a[i-1]=(a[i-1]+mod-a[j-1])%mod;
    }
    ans=(ans+(a[i-1]*i))%mod;
  }

  cout << ans << endl;
}