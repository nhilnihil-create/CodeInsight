#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, m;
  cin >> A >> B >> m;
  
  vector<int> a(A);
  for (int i = 0; i < A; i++) {
    cin >> a.at(i);
  }
  vector<int> b(B);
  for (int i = 0; i < B; i++) {
    cin >> b.at(i);
  }
  
  vector<int> x(m);
  vector<int> y(m);
  vector<int> c(m);
  for (int i = 0; i < m; i++) {
    cin >> x.at(i) >> y.at(i) >> c.at(i);
  }
  
  int ans;
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      ans = a.at(x.at(i) - 1) + b.at(y.at(i) - 1) - c.at(i);
    }
    else {
      ans = min(ans, a.at(x.at(i) - 1) + b.at(y.at(i) - 1) - c.at(i));
    }
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  ans = min(ans, a.at(0) + b.at(0));
  
  cout << ans << endl;
}