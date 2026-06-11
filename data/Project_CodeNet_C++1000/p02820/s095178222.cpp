#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int N, K, R, S, P;
  string T, U;
  cin >> N >> K >> R >> S >> P >> T;

  ll score = 0;
  for (int i = 0; i < N; i++) {
    if (i - K >= 0 && T[i - K] == T[i]) {
      if (T[i] == 'r' && U[i - K] == 'P') {
        U.push_back('R');
        continue;
      } else if (T[i] == 's' && U[i - K] == 'R') {
        U.push_back('S');
        continue;
      } else if (T[i] == 'p' && U[i - K] == 'S') {
        U.push_back('P');
        continue;
      }

      if (T[i] == 'r') {
        U.push_back('P');
        score += P;
        continue;
      } else if (T[i] == 's') {
        U.push_back('R');
        score += R;
        continue;
      } else if (T[i] == 'p') {
        U.push_back('S');
        score += S;
        continue;
      }
    }

    if (T[i] == 'r') {
      U.push_back('P');
      score += P;
    } else if (T[i] == 's') {
      U.push_back('R');
      score += R;
    } else if (T[i] == 'p') {
      U.push_back('S');
      score += S;
    }
  }
  cout << score << endl;
}