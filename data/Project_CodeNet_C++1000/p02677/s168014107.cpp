#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.14159265358979323846264338327950288
#define rep(i, k, n) for(ll i = k; i < n; i++)



int main(){
  long double a, b, h, m;
  cin >> a >> b >> h >> m;
  
  long double c1, c2;
  c1 = (60.0000000000*h + m) * PI /360.0000000000;
  c2 = m * PI / 30.0000000000;
  
  long double x1, x2, y1, y2;
  x1 = a * cos(c1);
  x2 = b * cos(c2);
  y1 = a * sin(c1);
  y2 = b * sin(c2);
  
  long double dist;
  dist = pow(x1-x2, 2.0000000000000) + pow(y1-y2, 2.0000000000000000);
  dist = pow(dist,0.500000000000000000);
  
  cout << fixed << setprecision(15) << dist << endl;
  
}
