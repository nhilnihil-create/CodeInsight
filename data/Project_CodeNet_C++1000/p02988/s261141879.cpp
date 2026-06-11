#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p.at(i);
  int num = 0;
  rep(i, n - 2) {
    if (p.at(i + 1) > p.at(i) && p.at(i + 1) < p.at(i + 2)) num++;
    else if (p.at(i + 1) < p.at(i) && p.at(i + 1) > p.at(i + 2)) num++;
  }
  cout << num << endl;
}