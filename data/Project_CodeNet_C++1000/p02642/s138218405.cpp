#include <bits/stdc++.h>
using namespace std;

const int MAX = 2100000;

int main() {
  int N;
  cin >> N;
  vector<long long> v(MAX, 0);
  for (int i = 0; i < N; ++i) {
    long long a;
    cin >> a;
    v[a]++;
  }
  for (int d = 1; d < MAX; ++d) {
    if (v[d] == 0) continue;
    if (v[d] > 1) v[d] = 0;
    for (int e = d * 2; e < MAX; e += d) {
      v[e] = 0;
    }
  }
  long long res = 0;
  for (int d = 1; d < MAX; ++d) res += v[d];
  cout << res << endl;
}
