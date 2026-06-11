#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr long long mod = 1e9 + 7;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> a(M);
  for (int i = 0; i < M; i++) {
    cin >> a[i];
    a[i]--;
  }

  int idx = 0;

  vector<long long> ways(N, 0LL);
  if (find(a.begin(), a.end(), 0) == a.end()) ways[0] = 1;
  else idx = distance(a.begin(), find(a.begin(), a.end(), 0));
  if (find(a.begin() + idx, a.end(), 1) == a.end()) ways[1] = 1;
  else idx = distance(a.begin(), find(a.begin(), a.end(), 1));

  for (int i = 1; i < N; i++) {
    if (find(a.begin() + idx, a.end(), i) != a.end()) {
      idx = distance(a.begin(), find(a.begin() + idx, a.end(), i));
      ways[i] = 0;
      continue;
    }

    if (i >= 1) ways[i] += ways[i-1];
    if (i >= 2) ways[i] += ways[i-2];

    ways[i] %= mod;
  }

  cout << ways[N-1] << endl;
  return 0;
}