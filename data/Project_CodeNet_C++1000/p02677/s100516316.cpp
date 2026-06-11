#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  cout << fixed << setprecision(18);
  double A, B, H, M, pi, C, ans;
  cin >> A >> B >> H >> M;
  pi=3.14159265358979323846;
  C=A*A+B*B-2*A*B*cos(((60*H-11*M)*pi)/360);
  ans=sqrt(C);
  cout << ans << endl;
}