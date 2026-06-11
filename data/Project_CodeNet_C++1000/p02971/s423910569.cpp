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
  int n,a[300000];
  cin >> n;
  int ma = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
  }

  bool flag = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++)
    if(a[i] == ma) cnt++;

  if(cnt > 1) flag = 1;
  
  int second = 0;
  for(int i = 0; i < n; i++) 
    if(second < a[i] & a[i] < ma) second = a[i];
  
  for(int i = 0; i < n; i++) {
    if(a[i] != ma || flag) 
      cout << ma << endl;
    else 
      cout << second << endl;
  }
}