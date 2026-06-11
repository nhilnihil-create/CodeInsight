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

int gcd(int x, int y) {
  if(x < y) swap(x,y);
  if(x % y == 0) return y;
  return gcd(y, x%y);
}

int main() {
  int k;
  cin >> k;

  long sum = 0;
  for(int a = 1; a <= k; a++) {
    for(int b = 1; b <= k; b++) {
      for(int c = 1; c <= k; c++) {
        sum += gcd(gcd(a,b),c);
      }
    }
  }
  cout << sum << endl;
}