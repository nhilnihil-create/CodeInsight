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
  int n,k,h[110000];
  cin >> n >> k;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cin >> h[i];
    if(h[i] >= k) cnt++;
  }
  
  cout << cnt << endl;  
}