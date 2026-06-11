#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {  // TODO
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];

  sort(A.begin(), A.end());
  int bigA = A[n - 1];
  vector<bool> at(bigA + 1, true);
  rep(i, A.size()) {
    if (i > 0 && A[i - 1] == A[i]) {
      at[A[i]] = false;
    }
    if (at[A[i]]) {
      int j = A[i];
      int ji = 2;
      while (j * ji <= bigA) {
        at[j * ji] = false;
        ji++;
      }
    }
  }
  int ans = 0;
  rep(i, A.size()) {
    if (at[A[i]]) ans++;
  }
  cout << ans << endl;

  return 0;
}