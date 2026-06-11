#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

int n, a[200005], s[200005];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int sum = 0;
  for (int i = 0; i < (n - 1); i += 2) {
    // a[i] ^ a[i + 1] == 0 ^ s[i] ^ s[i + 1] == s[i] ^ s[i + 1]
    sum = sum ^ a[i] ^ a[i + 1];
  }

  for (int i = 0; i < n; i++) {
    cout << (sum ^ a[i]) << endl;
  }
}