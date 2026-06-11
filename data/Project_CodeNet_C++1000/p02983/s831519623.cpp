#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  const int mod=2019;
  int ans=2018;
  int l,r; cin>>l>>r;
  int a,b,c,d;
  a=l/mod;
  b=l%mod;
  c=r/mod;
  d=r%mod;

  if(a!=c) ans=0;
  else {
    for(int i=b;i<d;i++) {
      for(int j=i+1;j<=d;j++) {
          ans=min(ans,i*j%mod);
      }
    }
  }
  cout<<ans<<endl;
}
