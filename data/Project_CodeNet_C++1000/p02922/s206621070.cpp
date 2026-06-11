#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int A,B;
  cin >> A >> B;
  
  int count = 0,num = 0;
  
  for (int i = 0; i < 30; i++) {
    if(i == 0){
      num += A;
    }else{
      num += A - 1;
    }
    count++;
    if(num >= B){
      if(B == 1){
              cout << "0" << endl;
      }else{
      cout << count << endl;
      }
      break;
    }

  }
 
}