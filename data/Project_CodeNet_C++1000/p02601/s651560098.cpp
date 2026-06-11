// B - Magic 2
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  // 初期値
  unsigned long long int A, B, C, K, i, j, k, sa, sb, sc; 
  cin >> A >> B >> C >> K;
  sa = A;
  sb = B;
  sc = C;
  
  bool hantei = false;
  
  //Main loop
  for(i = 0; i <= K; i++){
    if (i == 0){
      A = sa;
    } else {
      A *= 2;
    }
    for(j = 0; j <= K; j++){
      if (j == 0){
        B = sb;
      } else {
        B *= 2;
      }
      for(k = 0; k <= K; k++){
        if (k == 0){
         C = sc;
        } else {
          C *= 2;
        }
       
        if (B > A && C > B ){
          if (i + j + k <= K){
            hantei = true;
            // cout << A << " " << B << " " <<  C << ":" << ",magic=" << (B > A && C > B) << ", loop=" << (i + j + k == K) << endl; 
          }
        }
      }
    }
  }
  
  if (hantei){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}