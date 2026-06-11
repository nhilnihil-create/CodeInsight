#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> xs(N), ls(N);
  vector<P> ps(N);
  rep(i, N) {
    cin >> xs[i] >> ls[i];
    ps[i] = P(xs[i] + ls[i], xs[i] - ls[i]);
  }
  sort(ps.begin(), ps.end());
  int count = 1;
  int pos = ps[0].first;
  for (int i = 1; i < N; i++) {
    if (pos <= ps[i].second) {
      pos = ps[i].first;
      count++;
    }
  }
  cout << count << endl;

  return 0;
}