#include<iostream>
#include<math.h>
using namespace std;
using ll=long long;
int main(){

  ll N;
  cin>>N;
  ll x=0;
  ll y=0;
  ll ans=-1;
  for(ll i=1;i<=(ll)sqrt(N);i++){
  
    if(N%i==0){
    
      x=i;
      y=N/i;
      if(ans==-1||ans>x-1+y-1){
      
        ans=x-1+y-1;
      }
    }
  }
  cout<<ans;
}