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
  long a;
  double b;
  cin >> a >> b;
  long c = b*100 + 0.001;
  cout << a * c / 100 << endl; 
}
