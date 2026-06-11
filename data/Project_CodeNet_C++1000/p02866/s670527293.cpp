#include <bits/stdc++.h>
using namespace std;


long long pow(long long p,long long q,long long r){
  if(q==0)return 1;
  else if(q%2==0)return pow(p,q/2,r)*pow(p,q/2,r)%r;
  else return pow(p,q-1,r)*p%r;
}
int main() {
  int n;
  cin>>n;
  long long a[n],b[n];
  for(int i=0;i<n;i++){
    long long k;
    cin>>k;
    a[i]=k;
    b[i]=0;
  }
  long long ans=1,mod=998244353;
  if(a[0]!=0)ans=0;
  for(int i=1;i<n;i++){
    b[a[i]]++;
  }
  if(b[0]==0)b[0]=1;
  else ans=0;
  sort(a,a+n);
  for(int i=1;i<a[n-1]+1;i++){
    ans=ans*pow(b[i-1],b[i],mod)%mod;
  }
  cout<<ans<<endl;
}