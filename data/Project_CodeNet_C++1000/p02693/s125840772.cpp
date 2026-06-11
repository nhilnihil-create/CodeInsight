#include <bits/stdc++.h>
using namespace std;
int main() {
  int K, A, B;
  cin >> K >> A >> B;
  int C = K;
  for(int i = 0; i < 1000; i++) {
    if(C <= B) {
      C += K;
    }
    else {
      C -= K; 
      break;
    }
  }
  if(A <= C) {
    cout << "OK" << endl;
  }
  else {
    cout << "NG" << endl;
  }
}
