#include <bits/stdc++.h>
using namespace std;

long n,s,gyakugen,ans=0,mod=998244353;

long modpow(long modpow_x,long modpow_y) {
  long modpow_return=1;
  for(long i=1;i<=modpow_y;i*=2) {
    if(modpow_y/i%2==1) modpow_return=modpow_return*modpow_x%mod;
    modpow_x=modpow_x*modpow_x%mod;
  }
  return modpow_return;
}

int main() {
  cin >> n >> s;
  gyakugen=modpow(2,mod-2);
  vector<long> a(n);
  vector<long> wa(s-1);
  for(long i=0;i<n;i++) cin >> a[i];

  for(long i=0;i<n;i++) {
    ans=ans*2%mod;
    for(long j=s-1;j>0;j--) wa[j-1]=wa[j-1]*2%mod;
    for(long j=s-1;j>0;j--) {
      if(a[i]+j<s) wa[a[i]+j-1]=(wa[j-1]*gyakugen%mod+wa[a[i]+j-1])%mod;
      else if(a[i]+j==s) ans=(wa[j-1]*gyakugen%mod+ans)%mod;
    }
    if(a[i]<s) wa[a[i]-1]=(wa[a[i]-1]+modpow(2,i))%mod;  
    else if(a[i]==s) ans=(ans+modpow(2,i))%mod;
  }
  
  cout << ans << endl;
}