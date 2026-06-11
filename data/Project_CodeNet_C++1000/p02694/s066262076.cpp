#include <bits/stdc++.h>
using namespace std;

int main() {
  
  long x;
  cin >> x;
  
  long b = 100;
  
  for(int i = 0; i <= 376000; i++){
    b = b + (b / 100);
    if(b >= x){
      cout << i + 1 << endl;
      break;
    }
  }
  
  
}

