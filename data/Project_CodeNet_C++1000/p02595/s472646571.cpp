#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  int x, y, count = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    double dis = sqrt(pow(x,2) + pow(y,2));
    if (d >= dis) count++;
  }
  cout << count << endl;
}