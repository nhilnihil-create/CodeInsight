#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> T(N);
  int A;
  rep(i, N) {
    cin >> A;
    T[A - 1] = i + 1;
  }
  rep(i, N) cout << T[i] << " ";
  return 0;
}