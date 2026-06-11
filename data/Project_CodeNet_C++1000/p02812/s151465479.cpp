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
  int n;
  string s;
  cin >> n >> s;

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'A' & s[i+1] == 'B' & s[i+2] == 'C') {
      cnt++; i += 2;
    }
  }
  cout << cnt << endl;
}
