#include <bits/stdc++.h>
using namespace std; 
   
int main(){
  long long N,ans10=1,ans9=2,ans8=1,mod=1000000007,ans=0;
  cin >> N;
  for(int i=0;i<N;i++){
    ans10=(ans10*10)%mod;
    ans9=(ans9*9)%mod;
    ans8=(ans8*8)%mod;
  }
  ans=(ans10+ans8)%mod;
  ans=(ans-ans9)%mod;
  if(ans<0){
    ans+=mod;
  }
  cout << ans << endl;
}
    
  