#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  long a,b;
  cin >> a >> b;

  if(b - a >= 2019) {
    cout << 0 << endl;
    return 0;
  }
 
  int mi = 2020;
  for(int i = a; i <= b; i++) {
    for(int j = i+1; j <= b; j++) {
      mi = min(mi, (i%2019) * (j%2019) % 2019);
    }
  }
  cout << mi << endl; 
}
