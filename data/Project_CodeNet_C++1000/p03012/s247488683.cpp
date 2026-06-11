#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> w(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> w[i];
    sum += w[i];
  }

  int ans = INT_MAX;
  int r = sum;
  int l = 0;
  for (int i = 0; i < N - 1; i++) {
    r -= w[i];
    l += w[i];
    ans = min(ans, abs(r - l));
  }
  cout << ans << endl;
}
