#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,d;
  cin >> n >> d;
  
  for(int i = 1; i <= n; i++) {
    if((2*d+1)*i >= n) {
      cout << i << endl;
      return 0;
    }
  }
}