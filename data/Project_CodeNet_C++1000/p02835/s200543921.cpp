#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sum = 0;
  rep(_, 3) {
    int a;
    cin >> a;
    sum += a;
  }
  if (sum >= 22) {
    cout << "bust";
  } else {
    cout << "win";
  }
  return 0;
}
