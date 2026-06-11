#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
  int n,k;
  cin >> n>>k;
  long mod=1000000007;
  long ans=0;
  vector<long>d(k+1);
  for(int i=k;i>0;i--){
    d[i]=(d[i]+modpow(k/i,n,mod))%mod;
    for(int j=2;j*i<=k;j++){
      d[i]=(d[i]+mod-d[j*i])%mod;
    }
  }
  rep(i,k+1){
    ans=(ans+d[i]*i)%mod;
  }
  cout<<ans<<endl;
}