#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  long x,m = 100;
  cin >> x;
  for(long i = 1; ; i++) {
    m += m/100;
    if(x <= m) {
      cout << i << endl;
      return 0;
    }
  }
}