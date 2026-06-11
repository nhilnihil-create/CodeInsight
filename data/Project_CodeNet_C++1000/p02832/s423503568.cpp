#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;

  vector<int> a(N, 0);
  rep(i, N) cin >> a[i];

  int j = 1;
  rep(i, N) {
    if (a[i] == j) {
      j++;
    }
  }

  if (j == 1) {
    cout << -1 << endl;
  } else {
    cout << N - j + 1 << endl;
  }
}