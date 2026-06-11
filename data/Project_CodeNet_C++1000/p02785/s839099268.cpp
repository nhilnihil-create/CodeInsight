#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  int64_t sum = 0LL;
  for (int i = 0; i < N; i++) cin >> H.at(i);
  if (M >= N) {
    cout << 0 << endl;
  } else {
    sort(H.begin(), H.end());
    for (int i = 0; i < N - M; i++) {
      sum += H.at(i);
    }
    cout << sum << endl;
  }
}