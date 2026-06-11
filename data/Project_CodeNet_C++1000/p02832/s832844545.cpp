#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAX32 = 2147483647;
const double PI = 3.14159265358979323846;

int main() {
  long long n, input, tmp = 1, cnt = 0;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> input;
    if (input == tmp) {
      tmp++;
    } else {
      cnt++;
    }
  }
  if (tmp == 1) {
    cout << -1 << endl;
  } else {
    cout << cnt << endl;
  }
}
