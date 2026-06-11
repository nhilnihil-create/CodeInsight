#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), L(N);
  vector<pair<int, int>> range(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> L[i];
    range[i].first = X[i]+L[i];
    range[i].second = X[i]-L[i];
  }
  sort(range.begin(), range.end());
  int edge = -1000000000;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (edge <= range[i].second) {
      ans++;
      edge = range[i].first;
    }
  }
  cout << ans;
}
