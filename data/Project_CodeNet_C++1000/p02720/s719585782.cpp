#include <bits/stdc++.h>
using namespace std;

vector<long> L;

void dfs(long n) {
  if (n > 3234566667) return;
  L.push_back(n);
  int last = n % 10;
  int mi = max(0, last - 1);
  int mx = min(9, last + 1);
  for (int i = mi; i <= mx; i++) dfs(n * 10 + i);
}

int main() {
  int K;
  cin >> K;
  for (int i = 1; i <= 9; i++) dfs(i);
  sort(L.begin(), L.end());
  cout << L.at(K - 1) << "\n";
}