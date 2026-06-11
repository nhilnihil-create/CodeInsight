#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  if (N % 2 == 0) {
    cout << (N - 1) / 2 << endl;
  } else {
    cout << N / 2 << endl;
  }

  return 0;
}
