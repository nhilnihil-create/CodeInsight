#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  rep(i, n) { cin >> A[i]; }
  rep(i, k) {
    vector<int>  B(n + 1);
    rep(j, n) {
      int l = max(0, (j - A[j]));
      int r = min(j + A[j] + 1, n);
      B[l]++; B[r]--;
    }
    rep(j, n) B[j+1] += B[j];
    B.pop_back();
    if (A == B) break;
    A = B;
  }
  rep(i, n) {
    cout << A[i];
    if(i != n) cout << ' ';
  }
  cout << endl;
  return 0;
}