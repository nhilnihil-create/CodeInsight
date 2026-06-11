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
  int x;
  cin >> x;
  int sum = x/500 * 1000;
  x -= x/500 * 500;
  sum += x/5 * 5;

  cout << sum << endl;
}