#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K, S;
  cin >> N >> K >>S;
  vector<int> A(N,1);
  for (int i = 0; i < K; i++) A[i] = S;
  if (S < 1e9) {
    for (int i = K; i < N; i++) A[i] = S + 1;
  }
  for (int i = 0; i < N; i++) {
    cout << A[i];
    if (i != N - 1) cout << " ";
    else cout << endl;
  }
  return 0;
}
