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
  long a,b,k;
  cin >> a >> b >> k;
  
  if(a > k) cout << a-k << " " << b << endl;
  else cout << 0 << " " << max((long)0, b-(k-a)) << endl;
}