#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  
  vector<bool> ok(1000, false);
  for (int i = 0; i <= 9; i++){
    int num1 = 0;
    while (num1 < N){
      if (S.at(num1) - '0' == i){
        break;
      }
      num1++;
    }
    if (num1 == N){
      continue;
    }
    
    for (int j = 0; j <= 9; j++){
      int num2 = num1 + 1;
      while (num2 < N){
        if (S.at(num2) - '0' == j){
          break;
        }
        num2++;
      }
      if (num2 == N){
        continue;
      }
      
      for (int k = num2 + 1; k < N; k++){
        ok.at(i * 100 + j * 10 + (S.at(k) - '0')) = true;
      }
      
    }
  }
  
  int ans = 0;
  for (int i = 0; i < 1000; i++){
    if (ok.at(i) == true){
      ans++;
    }
  }
  
  cout << ans << endl;
}