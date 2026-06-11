#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  cout << accumulate(v.begin(), v.begin() + K, 0LL) << endl;
}
