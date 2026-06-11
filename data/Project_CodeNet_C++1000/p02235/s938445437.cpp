#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)

#define N 1000

int lcs(string X, string Y) {
  int m = X.size();
  int n = Y.size();
  int c[m + 1][n + 1];
  int maxlen = 0;
  X = ' ' + X;
  Y = ' ' + Y;
  c[0][0] = 0;
  FOR(i, 1, m + 1) c[i][0] = 0;
  FOR(j, 1, n + 1) c[0][j] = 0;

  FOR(i, 1, m + 1) {
    FOR(j, 1, n + 1) {
      if(X[i] == Y[j]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      } else {
        c[i][j] = max(c[i - 1][j], c[i][j - 1]);
      }
      maxlen = max(maxlen, c[i][j]);
    }
  }

  return maxlen;
}

int main(void) {
  string X, Y;
  int n; cin >> n;
  REP(i, n) {
    cin >> X >> Y;
    cout << lcs(X, Y) << endl;
  }
  return 0;
}