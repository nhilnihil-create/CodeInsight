#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m,ans=1,mod=1000000007;
  cin >> n >> m;
  vector<long> s(n),t(m),a(m,1);
  for(long i=0;i<n;i++) cin >> s[i];
  for(long i=0;i<m;i++) cin >> t[i];
  
  for(long i=0;i<n;i++) {
    long x=0;
    for(long j=0;j<m;j++) {
      if(s[i]==t[j]) {
        long y=(x+a[j])%mod;
        ans=(ans+a[j])%mod;
        a[j]=(a[j]+x)%mod;
        x=y;
      } else {
        a[j]=(a[j]+x)%mod;
      }
    }
  }
  cout << ans << endl;
}