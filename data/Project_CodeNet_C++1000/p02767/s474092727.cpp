#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), sum(N);
  for (int i = 0; i < N; i++) cin >> X[i];
  sort(X.begin(), X.end());
  int L = X[0];
  int R = X[N-1];
  int ans = INT_MAX;
  for (int i = L; i <= R; i++) {
    int cost = 0;
    for (int j = 0; j < N; j++) {
      cost += (X[j] - i) * (X[j] - i); 
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}