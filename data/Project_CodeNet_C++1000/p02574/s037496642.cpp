#include <bits/stdc++.h>
using namespace std;
const int MX = 1'000'000 + 1;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), p(MX);
  for (int &i : a) {
    cin >> i;
    p[i]++;
  }
  int pw = 1;
  for (int i = 2; i < MX; i++) {
    int cnt = 0;
    for (int j = i; j < MX; j += i) cnt += p[j];
    if (cnt > 1) { pw = 0; break; }
  }
  if (pw) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  int g = 0;
  for (int i = 0; i < n; i++) g = gcd(g, a[i]);
  if (g == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
  return 0;
}