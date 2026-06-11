#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  --a[0];
  bool found = false;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      found = true;
      break;
    } else if (a[i] > a[i - 1]) {
      --a[i];
    }
  }
  puts(found ? "No" : "Yes");
  return 0;
}