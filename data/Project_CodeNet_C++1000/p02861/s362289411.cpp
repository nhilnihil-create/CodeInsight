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
  double n,x[10],y[10];
  cin >> n;
  double p = 1;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    p *= i+1;
  }

  double sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i != j) {
        double dist_x = (x[i]-x[j])*(x[i]-x[j]);
        double dist_y = (y[i]-y[j])*(y[i]-y[j]);
        sum += sqrt(dist_x + dist_y);
      }
    }
  }
  sum *= p/n;
  cout << fixed << setprecision(15) << sum/p << endl;
}