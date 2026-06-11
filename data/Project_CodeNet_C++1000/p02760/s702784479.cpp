#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int main()
{
  int a,b,c;
  int v1[3][3];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      cin >> a;
      v1[i][j] = a;
    }
  }
  cin >> b;
  while (b--) {
    cin >> a;
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        if (a == v1[i][j]) {
          v1[i][j] = 0;
        }
      }
    }
  }
  for (size_t i = 0; i < 3; i++) {
    c = 0;
    for (size_t j = 0; j < 3; j++) {
      c+= v1[i][j];
    }
    if (c == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  for (size_t j = 0; j < 3; j++) {
    c = 0;
    for (size_t i = 0; i < 3; i++) {
      c+= v1[i][j];
    }
    if (c == 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if ((v1[0][0] + v1[1][1] + v1[2][2]) == 0) {
    cout << "Yes" << endl;
    return 0;
  }
  if ((v1[0][2] + v1[1][1] + v1[2][0]) == 0) {
    cout << "Yes" << endl;
    return 0;
  }


  cout << "No" << endl;


  return 0;
}
