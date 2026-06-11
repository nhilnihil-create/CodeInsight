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
  long n,k;
  cin >> n >> k;
  if(n >= k) {
    long t = n % k;
    cout << min(t,k-t) << endl;
  }
  else {
    cout << min(n, k-n) << endl;
  }
}