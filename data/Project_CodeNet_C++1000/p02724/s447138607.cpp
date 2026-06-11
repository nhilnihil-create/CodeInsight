#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int X, a, L, b, ans;
  cin >> X;
  a=(X-(X%500))/500;
  L=X%500;
  b=(L-(L%5))/5;
  ans=1000*a+5*b;
  cout << ans << endl;
}
