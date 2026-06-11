#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int Ai = 0;
  vector<int> A(N + 1);

  rep(i, N - 1) {
    cin >> Ai;
    A[Ai]++;
  }

  rep(i, N) cout << A[i + 1] << endl;

  return 0;
}