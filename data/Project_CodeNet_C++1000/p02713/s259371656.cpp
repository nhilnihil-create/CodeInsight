#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int K;
  cin>>K;
  
  long long ans=0;
  
  
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      for(int l=1;l<=K;l++){
        ans+=GCD(GCD(i,j),l);
      }
    }
  }
  
  cout<<ans<<endl;
}