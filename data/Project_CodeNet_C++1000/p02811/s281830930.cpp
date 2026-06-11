#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, x;
  cin >> k >> x;
  if (k * 500 >= x) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}