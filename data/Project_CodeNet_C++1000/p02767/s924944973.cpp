#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int n, x[N];

int calc(int p) {
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += (x[i] - p) * (x[i] - p);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int avg = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    avg += x[i];
  }
  avg /= n;
  cout << min(calc(avg), calc(avg + 1));
  return 0;
}