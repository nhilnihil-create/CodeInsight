#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int64_t f(int64_t x,int64_t y){
if(y==0)
  return 1;
  else if(y%2==0)
    return (f(x,y/2)*f(x,y/2))%mod;
  else
    return(x*((f(x,y/2)*f(x,y/2))%mod))%mod;
}
int main(){
  string s;
  cin>>s;
  int64_t N=s.size();
  int64_t ans=0; int64_t a=1;
  for(int64_t i=0;i<N;i++){
  if(s.at(i)=='1'){int64_t b=f(3,N-1-i); ans=(ans+b*a)%mod; a=(a*2)%mod;}
   }ans=(ans+a)%mod;
  cout<<ans<<endl;
  return 0;
}