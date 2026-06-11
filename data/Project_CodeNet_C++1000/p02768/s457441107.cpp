#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long func(long long x,long long n){
  if(n==0) return 1;
  else if(n%2==0){
    long long t=func(x,n/2);
    return (t*t)%mod;
  }
  else{
    long long y=func(x,n-1);
    return (x*y)%mod;
  }
}

int main() {
  long long n,a,b;
  cin>>n>>a>>b;
  long long ans=func(2,n)-1;
  long long xa=1;
  long long ya=1;
  long long n1=n;
  long long a1=1;
  for(int i=0;i<a;i++){
    xa*=n1;
    ya*=a1;
    xa%=mod;
    ya%=mod;
    n1--;
    a1++;
  }
  long long xb=1;
  long long yb=1;
  long long n2=n;
  long long a2=1;
  for(int i=0;i<b;i++){
    xb*=n2;
    yb*=a2;
    xb%=mod;
    yb%=mod;
    n2--;
    a2++;
  }
  long long aaa=func(ya,mod-2);
  long long bbb=func(yb,mod-2);
  aaa*=xa;
  aaa%=mod;
  bbb*=xb;
  bbb%=mod;
  ans-=aaa;
  ans-=bbb;
  if(ans>=0) ans%=mod;
  else{
    ans=mod-abs(ans)%mod;
  }
  cout<<ans<<endl;
}
