#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  // a + b + 2root(ab) < c
  // 4ab < (c- a - b)^2 and c-a-b >= 0

  if (4 * a * b < (c - a - b) * (c - a - b) && c - a - b >= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}