#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int N, M, K;
  cin >> N >> M >> K;
  vector<long long> A, B;

  long long n;
  A.push_back(0);
  for (int i = 0; i < N; i++) {
    cin >> n;
    A.push_back(n + A[i]);
  }

  B.push_back(0);
  for (int i = 0; i < M; i++) {
    cin >> n;
    B.push_back(n + B[i]);
  }

  int al = 0, ar = N, bl = 0, br = N, ai;
  if (A[al] > K) {
    ai = al;
  } else if (A[ar] <= K) {
    ai = ar;
  } else {

    while (ar - al != 1) {
      if (A[(al + ar) / 2] <= K) {
        al = (al + ar) / 2;
      } else {
        ar = (al + ar) / 2;
      }
    }
    ai = al;
  }
  int ans = 0, bi = 0;
  for (int i = ai; i >= 0; --i) {

    while (bi != M && B[bi+1] + A[i] <= K) bi++;
    ans = max(bi + i, ans);
  }

  cout << ans << endl;
  return 0;
}