#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X,K,D;
  cin >> X >> K >> D;
  
  if (X < 0){
    X *=-1;
  }
  
  if(X / D > K){
    cout << (X - K * D) << endl;  
  }else{
    K -= (X / D);
    X = X % D;
    if(K % 2 == 0){
      cout << X << endl;  
    }else{
      cout << (D - X) << endl;  
    }
  }
  
  
}
