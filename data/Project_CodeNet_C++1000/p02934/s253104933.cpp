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
  double n,a[200];
  cin >> n;
  double sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += 1/a[i];
  }

  cout << fixed << setprecision(10) << 1/sum << endl;  
}