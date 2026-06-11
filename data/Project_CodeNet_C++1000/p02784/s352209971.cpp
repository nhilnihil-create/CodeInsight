#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, n;
  cin >> h >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a;
  }
  if (h <= sum)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
  return 0;
}