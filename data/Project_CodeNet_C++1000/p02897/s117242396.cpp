#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;
  if (a%2==0) {
    cout << 0.50000000000000000 << endl;
  }
  else {
    cout << double((double(a)+1)/(2*double(a))) << endl;
  }
}
