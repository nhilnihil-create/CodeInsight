#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int h, a;
  cin >> h >> a;
  int x = 1;
  int i = 0;
  while(x){
    i++;
    h -= a;
    if(h <= 0){
      break;
    }
  }
  
  cout << i << endl;
  
  
}

