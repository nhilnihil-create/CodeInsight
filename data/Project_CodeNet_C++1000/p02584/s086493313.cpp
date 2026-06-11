#include<bits/stdc++.h>
using namespace std;

int main(){
  long X,K,D;
  cin >> X >> K >> D;
  long vk = abs(X) / D;
  long ans;
  if(vk >= K){
    if(X > 0){
      ans = abs(X - D * K);
    }else{
      ans = abs(D * K + X);
    }
  }else{
    if((vk % 2) == (K % 2)){
      if(X > 0){
        ans = abs(X - vk * D);
      }else{
        ans = abs(vk * D + X);
      }
    }else{
      if(X > 0){
        ans = abs(X - (vk + 1) * D); 
      }else{
        ans = abs((vk + 1) * D + X);
      }
    }
  }
  cout << ans <<endl;
  
}
  