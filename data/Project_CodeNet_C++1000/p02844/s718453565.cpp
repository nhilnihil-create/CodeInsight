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

  bool dp[30009][4][1009];
  dp[0][0][0] = true;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= 3; j++) {
      for(int k = 0; k < 1000; k++) {
        if(dp[i][j][k] == true) {
          dp[i+1][j][k] = true;
          if(j < 3) 
            dp[i+1][j+1][k*10 + (s[i] - '0')] = true;
        }
      }
    }
  }
  int cnt = 0;
  for(int i = 0; i < 1000; i++) 
    if(dp[n][3][i] == true) cnt++;
  cout << cnt << endl;
}