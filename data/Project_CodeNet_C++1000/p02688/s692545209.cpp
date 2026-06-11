#include <bits/stdc++.h>
#define FOR(i, c) for (int i = 0; i < c; i++)
#define MOD 1000000007
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> A(n+1, false);
  FOR(i, k) {
    int d; cin >> d;
    FOR(j, d) {
      int a; cin >> a;
      A[a] = true;
    }
  }

  int res = 0;
  FOR(i, n+1) {
    if (i && !A[i]) res++;
  }
  cout << res << endl;
  return 0;
}

