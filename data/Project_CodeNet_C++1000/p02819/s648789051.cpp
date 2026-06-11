#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  for (int i = X; true; i++){
    bool ans = true;
    for (int j = 2; j < sqrt(X); j++){
      if(i % j == 0) ans = false;
    }
    if (ans){
      cout << i << endl;
      break;
    }
  }
}  