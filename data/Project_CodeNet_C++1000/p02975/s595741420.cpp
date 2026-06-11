#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m[a] += 3;
  }
  vector<int> h;
  for (auto x : m) {
    if (x.second % n) {
      puts("No");
      return 0;
    }
    for (int i = 0; i < x.second / n; i++) {
      h.push_back(x.first);
    }
  }
  if (h.at(0) ^ h.at(1) ^ h.at(2)) {
    puts("No");
  } else {
    puts("Yes");
  }
}
