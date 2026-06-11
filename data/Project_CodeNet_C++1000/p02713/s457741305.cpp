#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
  if(x%y==0){
    return y;
  }
  return gcd(y,x%y);
}
int main(){
  int K;
  cin>>K;
  int64_t ans=0;
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      for(int l=1;l<=K;l++){
        ans+=gcd(i,gcd(j,l));
      }
    }
  }
  cout<<ans<<endl;
}
