#include <bits/stdc++.h>
using namespace std;  

int main() {
  int n;
  cin >> n;
  
  int y = 10000 - n;
  
  while(true){
    if(y < 1000) break;
    y -= 1000;
  }
  
  cout << y << endl;
  return 0;
}