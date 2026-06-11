#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  n = (n * (n - 1)) / 2;
  m = (m * (m - 1)) / 2;
  n = n + m;
  cout << n << endl;
}