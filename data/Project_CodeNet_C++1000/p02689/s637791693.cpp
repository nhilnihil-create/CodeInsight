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
const long INF = 2000000000;

int main() {
  int n,m,h[110000],ma[110000];
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
    ma[i] = 0;
  }
  for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    ma[a] = max(ma[a], h[b]);
    ma[b] = max(ma[b], h[a]);
  }
  
  int cnt = 0;
  for(int i = 1; i <= n; i++)
    if(h[i] > ma[i]) cnt++;
  
  cout << cnt << endl;
}