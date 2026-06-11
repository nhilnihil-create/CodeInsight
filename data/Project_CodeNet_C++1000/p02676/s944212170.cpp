// ABC168 B Triple Dots
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  // 初期値
  int K, length;
  string S;
  cin >> K >> S;
  length = S.size();
  
  //Main loop
  for (int i = 0; i < length; i++){
    if (i < K){
      cout << S.at(i);
    } else if (i == K){
      cout << "...";
      break;
    }
  }
   
  return 0;
}