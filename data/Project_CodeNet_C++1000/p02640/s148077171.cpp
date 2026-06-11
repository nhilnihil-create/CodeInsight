#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x,y; 
  cin >> x>> y;
  for (int c =0; c<=x; c++){
    int t= x-c;
    int asi = c*2+t*4;
    if (asi == y) {
      cout << "Yes" << endl;
      return 0;
    }
  }  
  cout << "No" << endl;
  return 0;
 }
