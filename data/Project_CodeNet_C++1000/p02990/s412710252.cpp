#include <bits/stdc++.h>
using namespace std;
long long pow(long long p,long long q,long long r){
  if(q==0)return 1;
  else if(q%2==0)return pow(p,q/2,r)*pow(p,q/2,r)%r;
  else return pow(p,q-1,r)*p%r;
}
int main() {
  long long n,k,mod=1000000007;
  cin>>n>>k;
  long long a[k];
  a[0]=n-k+1;
  for(int i=1;i<k;i++){
    a[i]=(a[i-1]*(k-i)*(n-k+1-i)%mod)*pow(i,mod-2,mod)%mod*pow(i+1,mod-2,mod)%mod;
  }
  for(int i=0;i<k;i++){
    cout<<a[i]<<endl;
  }
}
