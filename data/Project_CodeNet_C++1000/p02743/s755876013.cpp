#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll left = 4 * a * b;
  ll num = c - a - b;
  ll right = num * num;

  if (num < 0) {
    cout << "No" << endl;
    return 0;
  }

  if (left < right) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
