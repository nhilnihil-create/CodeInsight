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
  
  int mi = k+1,sum;
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      sum = min(k - (a[1]-a[0]),
      k - (k-a[n-1]) - a[0]);
    }
    else if(i == n-1) {
      sum = min(k - (k-a[n-1]) - a[0],
      k - (a[n-1]-a[n-2]));
    }
    else {
      sum = min(k - (a[i]-a[i-1]), 
      k - (a[i+1]-a[i]));
    }
    mi = min(mi, sum);
  }

  cout << mi << endl;
}