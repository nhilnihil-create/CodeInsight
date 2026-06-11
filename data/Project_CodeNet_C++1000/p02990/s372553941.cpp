#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int64_t f(int64_t x,int64_t y){
if(y==0)
  return 1;
  else if(y%2==0)
    return (f(x,y/2)*f(x,y/2))%mod;
  else
    return (((x*f(x,y/2))%mod)*f(x,y/2))%mod;

}
int main(){
int64_t N,K;
  cin>>N>>K;
  int64_t ans=N-K+1;
  cout<<N-K+1<<endl;
  for(int64_t i=2;i<=K;i++){
  int64_t a=(N-K+2-i);
    int64_t b=(K+1-i);
    int64_t c=f(i*(i-1),mod-2);
    ans=(((ans*a)%mod)*((b*c)%mod))%mod;
    cout<<ans<<endl;
  }
  return 0;
}