#include <bits/stdc++.h>
using namespace std;
long long mod(int n){
  long long p=1000000000+7;
  if(n==1) return 2;
  if(n%2==0) return mod(n/2)*mod(n/2)%p; 
  if(n%2==1) return 2*mod(n-1)%p; 
}
long long from_up(int n,int r){
  long long p=1000000000+7;
  if(r==1) return n;
  if(r>1) return from_up(n,r-1)*(n-r+1)%p;
}
long long bunbo_1(int r,int P){
   long long p=1000000000+7;
  if(P==1) return from_up(r,r);
  if(P%2==0) return bunbo_1(r,P/2)*bunbo_1(r,P/2)%p; 
  if(P%2==1) return from_up(r,r)*bunbo_1(r,P-1)%p; 
}
long long nCr_mod(int n,int r){
  long long p=1000000000+7;
  return from_up(n,r)*bunbo_1(r,p-2)%p;
}
int main() {
 int n,a,b;
  cin>>n>>a>>b;
  int p=1000000000+7;
  long long ans=mod(n)-1-nCr_mod(n,a)-nCr_mod(n,b);
  if(ans>0) ans%=p;
  if(ans<0){
    while(ans<0) ans+=p;
  }
  cout<<ans<<endl;
}
 
  