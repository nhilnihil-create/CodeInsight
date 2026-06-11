#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  vector<int> xs(3);
  rep(i, 3) cin >> xs[i];
  cout << xs[2] << " " << xs[0] << " " << xs[1] << endl;
  return 0;
}