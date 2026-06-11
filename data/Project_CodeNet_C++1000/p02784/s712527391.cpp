#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, n;
  cin >> h >> n;
  int sum = 0;
  while (n--) {
    int a;
    cin >> a;
    sum += a;
  }
  if (sum >= h) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
