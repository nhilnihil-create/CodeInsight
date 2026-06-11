#include <iostream>
using namespace std;
int main(){
  int A, B, answer;
  cin >> A >> B;
  for (int i = 1; i < 1000000; i++){
    if (i == 1){
      answer = A;
    }
    else{
      answer += A - 1;
    }
    if (answer >= B){
      if (B == 1) cout << 0;
      else cout << i;
      break;
    }
  }
}
