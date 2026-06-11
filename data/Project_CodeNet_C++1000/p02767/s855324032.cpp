#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i = 0; i < n; i++) cin >> x.at(i);
  int s = 0, t = 0;
  for(int X : x) {
    s += X;
    t += X * X;
  }
  int p = s / n;
  int m1 = (n * p * p) - (2 * p * s);
  p++;
  int m2 = (n * p * p) - (2 * p * s);
  int m = min(m1, m2);
  cout << m + t << endl;
}