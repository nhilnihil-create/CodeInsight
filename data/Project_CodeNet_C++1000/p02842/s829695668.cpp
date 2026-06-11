#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  int cal;
  for (int i = 1; i <= n; ++i) {
    cal = (double)i * 1.08;
    if (cal == n) {
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(\n";
}
