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
  long n;
  cin >> n;
  
  long mi = 1e13;
  for(long i = 1; i <= sqrt(n); i++) {
    long ans;
    long j = n/i;
    if(i*j == n)
      ans = (i-1)+(j-1);
    mi = min(mi, ans);
  }
  cout << mi << endl;
}