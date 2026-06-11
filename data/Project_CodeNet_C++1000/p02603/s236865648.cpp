#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int Nmax = 100;
int A[Nmax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  ll res = 1000;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    if (i > 0 && A[i] > A[i - 1]) {
      ll unit = res / A[i - 1];
      res = res - unit * A[i - 1] + unit * A[i];
    }
  }
  cout << res << endl;
  return 0;
}
