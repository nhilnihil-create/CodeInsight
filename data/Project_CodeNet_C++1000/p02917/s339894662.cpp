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
  int n,b[110];
  cin >> n;
  for(int i = 0; i < n-1; i++)
    cin >> b[i];

  b[n-1] = 110000;
  int sum = 0;
  for(int i = n-1; i > 0; i--)
    sum += min(b[i], b[i-1]);
  
  cout << sum + b[0] << endl;
}