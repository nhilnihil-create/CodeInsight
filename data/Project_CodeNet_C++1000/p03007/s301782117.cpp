#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A, B;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a > 0) {
      A.emplace_back(a);
    } else {
      B.emplace_back(a);
    }
  }

  vector<pair<int, int>> P;
  auto f = [&](int a, int b) {
    P.emplace_back(make_pair(a, b));
    return a - b;
  };

  int res = 0;
  if ((int)A.size() == N || (int)B.size() == N) {
    if ((int)A.size() == N) {
      sort(A.begin(), A.end());

      for (int i = 0; i < N - 2; i++) {
        int a = f(A[i], A[i + 1]);
        A[i + 1] = a;
      }

      res = f(A[N - 1], A[N - 2]);
    } else {
      sort(B.begin(), B.end(), greater<int>());

      for (int i = 0; i < N - 1; i++) {
        int b = f(B[i], B[i + 1]);
        B[i + 1] = b;
      }

      res = B[N - 1];
    }
  } else {
    int a = A[0];
    for (int i = 1; i < (int)A.size(); i++) {
      B[0] = f(B[0], A[i]);
    }

    for (int i = 0; i < (int)B.size(); i++) {
      a = f(a, B[i]);
    }

    res = a;
  }

  cout << res << '\n';
  for (int i = 0; i < (int)P.size(); i++) {
    cout << P[i].first << " " << P[i].second << '\n';
  }
  return 0;
}
