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
const long INF = 1e9 + 1;

int main() { 
  int n,m,x;
  cin >> n >> m >> x;
  int c[n],a[n][m];
  for(int i = 0; i < n; i++) {
    cin >> c[i];
    for(int j = 0; j < m; j++)
      cin >> a[i][j];
  }

  int mi = INF;
  for(int bit = 0; bit < (1 << n); bit++) {
    int num = 0,sum[m];
    for(int i = 0; i < m; i++) sum[i] = 0;
    for(int i = 0; i < n; i++) {
      if(bit & (1 << i)) {
        num += c[i];
        for(int j = 0; j < m; j++) sum[j] += a[i][j];
      }
    }
    bool flag = 1;
    for(int j = 0; j < m; j++) {
      if(sum[j] < x) {
        flag = 0; break;
      }
    }
    if(flag) mi = min(mi,num);
  }
  
  if(mi == INF) cout << -1 << endl;
  else cout << mi << endl;
}