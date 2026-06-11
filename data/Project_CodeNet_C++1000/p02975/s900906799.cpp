#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  map<int, int> m;
  for (int i = 0; i < n; i++) m[a.at(i)]++;
  if (m[0] == n) {
    puts("Yes");
    return 0;
  } else if (n % 3) {
    puts("No");
    return 0;
  }
  vector<int> h;
  for (auto x : m) {
    if (x.second % (n / 3)) {
      puts("No");
      return 0;
    }
    for (int i = 0; i < x.second / (n / 3); i++) {
      h.push_back(x.first);
    }
  }
  if ((h.at(0) ^ h.at(1) ^ h.at(2)) == 0) {
    puts("Yes");
  } else {
    puts("No");
  }
}
