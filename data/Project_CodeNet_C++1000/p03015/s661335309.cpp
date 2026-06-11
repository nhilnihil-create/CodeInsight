#include <bits/stdc++.h>
using namespace std;

long ans=1,aaa,mod=1000000007,invele;
string l;

long modpow(long modpow_x,long modpow_y) {
  long modpow_return=1;
  for(long i=1;i<=modpow_y;i*=2) {
    if(modpow_y/i%2==1) modpow_return=modpow_return*modpow_x%mod;
    modpow_x=modpow_x*modpow_x%mod;
  }
  return modpow_return;
}

int main() {
  cin >> l;
  invele=modpow(3,mod-2);
  for(long i=0;i<l.size();i++) ans=ans*3%mod;
  aaa=ans*invele%mod*2%mod;
  for(long i=1;i<l.size();i++) {
    if(l[i]=='1') {
      aaa=aaa*invele%mod*2%mod;
    } else {
      ans=(ans+(mod-aaa*invele%mod*2%mod))%mod;
      aaa=aaa*invele%mod;
    }
  }
  cout << ans << endl;
}