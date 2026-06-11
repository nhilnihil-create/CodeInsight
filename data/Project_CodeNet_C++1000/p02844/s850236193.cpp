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
  string s;
  cin >> n >> s;

  int cnt = 0;
  for(int i = 0; i < 1000; i++) {
    int a[3] = {i/100, (i/10)%10, i%10}, process = 0;
    for(int j = 0; j < n; j++) {
      if(process <= 2 & a[process] == (int)(s[j]-'0')) process++;
    }
    if(process == 3) cnt++;
  }
  cout << cnt << endl;
}