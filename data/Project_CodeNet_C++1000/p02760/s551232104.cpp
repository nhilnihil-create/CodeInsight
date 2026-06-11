#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,a[10][10],b[100],c[10][10];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> a[i][j];
      c[i][j] = 0;
    }
  }
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> b[i];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(b[i] == a[j][k]) 
          c[j][k] = 1;
      }
    }
  }
  for(int i = 0; i < 3; i++) {
    if(c[i][0] == 1 & c[i][1] == 1 & c[i][2] == 1) {
      cout << "Yes" << endl;
      return 0;
    }
    if(c[0][i] == 1 & c[1][i] == 1 & c[2][i] == 1) {
      cout << "Yes" << endl;
      return 0;
    }
    if(c[0][0] == 1 & c[1][1] == 1 & c[2][2] == 1) {
      cout << "Yes" << endl;
      return 0;
    }
    if(c[0][2] == 1 & c[1][1] == 1 & c[2][0] == 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
