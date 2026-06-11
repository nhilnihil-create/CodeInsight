#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
const double PI = acos(-1.0);
const long mod = 1000000007;

int main() {
  int x;
  cin >> x;
  for(int i = 1; i <= x; i++) {
    if(100*i <= x & x <= 105*i) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
}