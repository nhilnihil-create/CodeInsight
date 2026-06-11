#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n;
const int mod=1e9+7;
int ksm(int x,int y){
  int z=1;
  while(y){
    if(y&1)z=1ll*z*x%mod;
    x=1ll*x*x%mod;
    y>>=1;
  }
  return z;
}
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  if(n<=1)cout<<0<<'\n';
  else{
    cout<<(ksm(10,n)-(2ll*ksm(9,n)-ksm(8,n)+mod)%mod +10ll*mod)%mod<<'\n';
  }
  return 0;
}
