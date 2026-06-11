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
  long n,a,b;
  cin >> n >> a >> b;

  long sum = n / (a+b) * a;
  sum += min(n % (a+b), a);

  cout << sum << endl;
}