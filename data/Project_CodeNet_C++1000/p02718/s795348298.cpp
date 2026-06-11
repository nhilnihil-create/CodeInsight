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
  int n,m,a[2000];
  cin >> n >> m;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(a[i]*4*m >= sum) cnt++;
  }
  if(cnt >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
}