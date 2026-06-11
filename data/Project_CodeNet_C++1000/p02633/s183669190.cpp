#include <bits/stdc++.h>
using namespace std;

int main(){
  long long X;
  cin >> X;
  
  long long ans = 360;
  for (long long i = 0; i < 3; i++){
    if (X % 2 == 0){
      X /= 2;
      ans /= 2;
    }
  }
  for (long long i = 0; i < 2; i++){
    if (X % 3 == 0){
      X /= 3;
      ans /= 3;
    } 
  }
  for (long long i = 0; i < 1; i++){
    if (X % 5 == 0){
      X /= 5;
      ans /= 5;
    }
  }
  cout << ans;
}