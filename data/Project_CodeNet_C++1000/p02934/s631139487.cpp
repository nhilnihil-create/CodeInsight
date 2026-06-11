#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  float k = 0.0;
  rep(i, n) k += (float) 1 / a.at(i);
  cout << setprecision(15) << (float) 1 / k << endl;
}
