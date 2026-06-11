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

const long INF = (1<<30);

int main() {
  int k,n;
  cin >> k >> n;
  int a[n+1];
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  int ma = 0,dist;
  for(int i = 0; i < n; i++) {
    if(i == n-1) 
      dist = abs(a[i] - k) + a[0];
    else
      dist = abs(a[i] - a[i+1]);
    
    ma = max(ma, dist);
  }

  cout << k - ma << endl;
}