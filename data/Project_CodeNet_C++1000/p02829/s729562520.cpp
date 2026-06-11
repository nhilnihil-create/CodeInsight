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
  int a,b;
  cin >> a >> b;
  if(a > b) swap(a,b);
  if(a == 1 & b == 2) cout << 3 << endl;
  else if(a == 1 & b == 3) cout << 2 << endl;
  else if(a == 2 & b == 3) cout << 1 << endl;
}
