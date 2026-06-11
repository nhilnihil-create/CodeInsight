#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N<=9) {
    cout << N << endl;
  }
  else {
    if (N<=99) {
      cout << 9 << endl;
    }
    else {
      if (N<=999) {
        cout << N-90 << endl;
      }
      else {
        if (N<=9999) {
          cout << 909 << endl;
        }
        else {
          if (N<=99999) {
            cout << N-9090 << endl;
          }
          else {
            cout << 90909 << endl;
          }
        }
      }
    }
  }
}