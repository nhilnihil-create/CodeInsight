#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int x,y;
  cin >> x >> y;
  
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j <=100; j++) {
      if(i+j == x & i*2+j*4 == y) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}