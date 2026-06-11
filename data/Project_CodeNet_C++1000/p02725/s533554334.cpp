#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  a.push_back(a.at(0) + k);
  int m = 0;
  for(int i = 0; i < n; i++) {
    m = max(m, a.at(i+1) - a.at(i));
  }
  cout << k - m << endl;
}