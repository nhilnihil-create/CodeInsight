#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a, b; cin >> k >> a >> b;
  cout << ((a + k - 1) / k * k <= b ? "OK" : "NG") << endl;
}