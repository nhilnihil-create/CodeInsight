#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N;
  string S;
  cin >> N >> S;
  
  int count = 0;
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        int judge = 0;
        for (int l = 0; l < N; l++) {
          int A = S.at(l) - '0';
          if (A == k && judge == 2){
            judge++;
          }
          if (A == j && judge == 1){
            judge++;
          }
          if (A == i && judge == 0){
            judge++;
          }
          if (judge == 3){
            count++;
            break;
          }
        }
      }
    }
  }
  cout << count << endl;
}
          
            
          
    
    
      
      