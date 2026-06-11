#include <bits/stdc++.h>

//#include <atcoder/all>

using namespace std;
// using namespace atcoder;
using ll = long long;

int main() {
  int n;
  cin >> n;

  if (n & 1) {
    cout << n / 2 << endl;
  } else {
    cout << n / 2 - 1 << endl;
  }
}