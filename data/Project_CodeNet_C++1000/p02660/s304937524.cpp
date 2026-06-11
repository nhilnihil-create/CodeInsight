#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N; cin>>N;
  int ans=0;
  for(int i=2;i<100000000;i++){
    if(N%i==0){
      N/=i;
      int count=1;
      for(;;){
        if(N%i!=0)break;
        count++;
        N/=i;
      }
      for(int j=0;;j++){
        if(j*(j+1)/2>count){
          ans+=j-1;
          break;
        }
      }
    }
    if(N==1)break;
  }
  if(N!=1)ans++;
  cout<<ans<<endl;
}