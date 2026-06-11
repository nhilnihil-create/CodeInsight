#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    p--;
    if (p != i) {
      cnt++;
    }
  }

  if (cnt <= 2) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}
