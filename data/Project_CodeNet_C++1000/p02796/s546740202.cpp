#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X, L;
  cin >> N;

  vector<pair<long long, long long>> R(N);
  for (int i = 0; i < N; i++) {
    cin >> X >> L;
    R.at(i) = make_pair(X + L, X - L);
  }

  sort(R.begin(), R.end());

  int res = 0;
  int cnt = -1001001001;
  for (int i = 0; i < N; i++) {
    long long E, S;
    tie(E, S) = R.at(i);
    if (cnt <= S) {
      cnt = E;
      res ++;
    }
  }

  cout << res << endl;
}