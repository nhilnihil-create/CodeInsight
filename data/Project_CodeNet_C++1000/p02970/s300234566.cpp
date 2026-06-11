#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, d;
  cin >> n >> d;
  int haba = 2 * d + 1;

  cout << (n + haba - 1) / haba << endl;

  return 0;
}
