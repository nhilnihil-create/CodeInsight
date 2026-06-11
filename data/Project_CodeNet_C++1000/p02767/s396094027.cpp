#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int energy(vector<int> vec, int p) {
  int enesum = 0;
  rep(i, vec.size()) enesum += (vec.at(i) - p) * (vec.at(i) - p);
  return enesum;
}

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  rep(i, N) cin >> X.at(i);
  int ans = 1000000000;
  sort(X.begin(), X.end());
  for (int i = X.at(0); i < X.at(N - 1) + 1; i++) {
    if (energy(X, i) < ans) ans = energy(X, i);
  }
  cout << ans;
}
