#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, R;
  cin >> A >> B;
  R=(B-1)%(A-1);
  if (R==0) {
    cout << (B-1)/(A-1) << endl;
  }
  else {
    cout << (B-1-R)/(A-1)+1 << endl;
  }
}