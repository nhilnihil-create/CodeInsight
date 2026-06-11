#include <bits/stdc++.h>
using namespace std;

vector<long> V;

void dfs(long n) {
  if (n > 3234566667) return;
  V.push_back(n);
  int mi = max(0L, n % 10 - 1);
  int mx = min(9L, n % 10 + 1);
  for (long i = mi; i <= mx; i++) dfs(n * 10 + i);
}

int main() {
  int K;
  cin >> K;
  for (int i = 1; i <= 9; i++) dfs(i);
  sort(V.begin(), V.end());
  cout << V.at(K - 1) << "\n";
}