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

int main() {
  long n,a[110000],b[110000];
  cin >> n;
  for(int i = 0; i < n+1; i++)
      cin >> a[i];
  for(int i = 0; i < n; i++)
      cin >> b[i];
  
  long cnt = 0;
  for(int i = 0; i < n; i++) {
    if(b[i] <= a[i]) cnt += b[i];
    else {
      if(a[i+1] - b[i] + a[i] >= 0) {
        cnt += b[i];
        a[i+1] -= (b[i] - a[i]);
      }
      else {
        cnt += a[i] + a[i+1];
        a[i+1] -= (b[i] - a[i]);
        if(a[i+1] < 0) a[i+1] = 0;
      }
    }
  }
  cout << cnt << endl;
}