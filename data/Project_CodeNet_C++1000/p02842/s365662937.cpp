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
  int n;
  cin >> n;
  for(int i = n/1.1; i <= n; i++) {
    if((int)(i*1.08) == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}
