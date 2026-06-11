#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  double sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sum /= (4 * m);
  if(a.at(m - 1) < sum) cout << "No" << endl;
  else cout << "Yes" << endl;
}