#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;

  int p[N];
  rep(i, N) cin >> p[i];

  int cnt = 0;
  rep(i, N) {
    if (p[i] != i + 1) {
      cnt++;
    }
  }

  if (cnt <= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
