#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  int keta = 0;
  while (0 < n) {
    n /= k;
    keta++;
  }
  cout << keta << endl;
  return 0;
}
