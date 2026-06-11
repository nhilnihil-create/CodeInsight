#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  int n = 1;
  
  while(true){
    if((n * X) % 360 == 0){
      cout << n << endl;
      break;
    }
    else{
      n++;
    }
  }
}