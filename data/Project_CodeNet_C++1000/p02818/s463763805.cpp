#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int64_t A, B, K;
  cin >> A >> B >> K;
  if (A>=K) {
    cout << A-K << " " << B << endl;
  }
  else {
    if (A+B>=K) {
      cout << 0 << " " << A+B-K << endl;
    }
    else {
      cout << 0 << " " << 0 << endl;
    }
  }
}