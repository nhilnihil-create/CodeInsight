#include <bits/stdc++.h>
using namespace std;

void rec(int d, long long val, vector<long long> &all) {
  all.push_back(val);

  if (d == 10) return;

  for (int j = -1; j <= 1; ++j) {
    int add = (val % 10) + j;
    if (add >= 0 && add <= 9) rec(d + 1, val * 10 + add, all);
  }
}

int main() {
  int K;
  cin >> K;
  vector<long long> all;
  for (int v = 1; v < 10; ++v) rec(1, v, all);

  sort(all.begin(), all.end());

  cout << all[K - 1] << endl;
}
