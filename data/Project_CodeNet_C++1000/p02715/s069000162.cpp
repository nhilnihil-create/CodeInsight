#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int64_t POW(int64_t x,int64_t y){
if(y==0)
  return 1;
  else if(y%2==0)
    return (POW(x,y/2)*POW(x,y/2))%mod;
  else
    return ((((x%mod)*POW(x,y/2))%mod)*POW(x,y/2))%mod;
}
int main(){
int64_t N,K;
  cin>>N>>K;
  vector<int64_t>ans(K+1);
  for(int i=K;1<=i;i--){
  int64_t a=POW(K/i,N);
    for(int j=2;j<=K/i;j++){
    a=(a-ans.at(i*j)+mod)%mod;
    }ans.at(i)=a;
  
  }int64_t A=0;
  for(int i=1;i<=K;i++){
  A=(A+ans.at(i)*i)%mod;
  }cout<<A<<endl;
   return 0;
}