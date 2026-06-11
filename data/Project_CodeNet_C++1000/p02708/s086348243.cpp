#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

long long f(int n,int k){
  long long s;
  s=((n-k+1)%mod)*(k%mod);
  s=(s+1)%mod;
  return s;
}
int main() {
  int n,k;
  long long ans=0;
  cin>>n>>k;
  for(int i=k;i<=n+1;i++){
  	ans=(ans+f(n,i))%mod;
  }
  cout<<ans<<endl;
}
