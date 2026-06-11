#include "bits/stdc++.h"
using namespace std;

int solve(int K){
  
  if(K % 2 == 0 || K % 5 == 0){
    return -1;
  }
  
  else{
    int pre_amari = 0;
    for(int i=1;i<=K;i++){
      int amari = (pre_amari * 10 + 7) % K;
      if(amari == 0)
        return i;
      pre_amari = amari;
  	}
  }
  
  return -1;
}

int main(){
  
  int K;
  cin >> K;

  cout << solve(K);
  return 0;
}