#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a.at(i);
  }

  int64_t money = 1000;
  for (int i = 1; i < n; i++) {
    if (a.at(i) < a.at(i + 1)) {
      int64_t stock = money / a.at(i);
      money += stock * (a.at(i + 1) - a.at(i));
    }
  }

  cout << money << endl;
}