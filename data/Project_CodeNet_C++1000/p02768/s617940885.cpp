#include <bits/stdc++.h>
using namespace std;
long long pow(long long p,long long q,long long r){
  if(q==0)return 1;
  else if(q%2==0)return pow(p,q/2,r)*pow(p,q/2,r)%r;
  else return pow(p,q-1,r)*p%r;
}
long long pCq(long long p,long long q,long long r){
  if(q==0)return 1;
  else {
    return pCq(p,q-1,r)*(p-q+1)%r*pow(q,r-2,r)%r;
  }
}
int main() {
  long long n,a,b,ans=0;
  cin>>n>>a>>b;
  long long mod=1000000007;
  ans=pow(2,n,mod)-1-pCq(n,a,mod)-pCq(n,b,mod);
  while(ans<0)ans+=mod;
  cout<<ans<<endl;
}