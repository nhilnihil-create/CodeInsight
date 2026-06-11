#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  sort(S.begin(), S.end());
  int A = 0;
  vector<string> ans(N);
  int B = 0;
  int n = 0;
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      B++;
      if (A < B) {
        ans = vector<string>(N, " ");
        n = 0;
        ans.at(n) = S.at(i);
        A = B;
        B = 0;
      }
      else if (A == B) {
        n++;
        ans.at(n) = S.at(i);
        B = 0;
      }
      else {
        B = 0;
      }
    }
    else if (S.at(i) == S.at(i + 1)) {
      B++;
    }
    else {
      B++;
      if (A < B) {
        ans = vector<string>(N, " ");
        n = 0;
        ans.at(n) = S.at(i);
        A = B;
        B = 0;
      }
      else if (A == B) {
        n++;
        ans.at(n) = S.at(i);
        B = 0;
      }
      else {
        B = 0;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    cout << ans.at(i) << endl;; 
  }
}
  