#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, h, m;
  const double PI = acos(-1);
  cin >> a >> b >> h >> m;
  double th = double(60*h+m)*(PI/360);
  double tm = double(m)*(PI/30);
  double rad = abs(th-tm);
  double ans = a*a+b*b-2*a*b*cos(rad);
  ans = sqrt(ans);
  cout << fixed << setprecision(20) << ans;
}
