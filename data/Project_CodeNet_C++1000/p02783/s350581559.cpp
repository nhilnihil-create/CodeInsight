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
  int h,a;
  cin >> h >> a;
  
  int cnt = 0;
  while(h > 0) {
    h -= a;
    cnt++;
  }
  cout << cnt << endl;
}
