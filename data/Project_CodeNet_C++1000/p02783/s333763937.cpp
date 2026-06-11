#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int H, A;
  cin >> H >> A;
  if (H%A==0) {
    cout << H/A << endl;
  }
  else {
    cout << 1+(H-(H%A))/A << endl;
  }
}