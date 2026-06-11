#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> as(N);
  int sum = 0;
  rep(i, N) {
    cin >> as[i];
    sum += as[i];
  };
  double a = (double)sum / 4.0 / (double)M;
  int count = 0;
  rep(i, N) {
    if (a <= as[i]) {
      count++;
    }
  }
  if (M <= count) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}