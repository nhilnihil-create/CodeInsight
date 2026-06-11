#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N) A[i] = -1;
  rep(i, M) {
    int S, C;
    cin >> S >> C;
    --S;
    if (A[S] == -1) A[S] = C;
    else if (A[S] != C) {
      puts("-1");
      return 0;
    }
  }
  if (N == 1) {
    if (A[0] == -1) {
      puts("0");
      return 0;
    } else {
      cout << A[0] << '\n';
      return 0;
    }
  }
  if (A[0] == -1) A[0] = 1;
  else if (A[0] == 0) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i < N; i++) {
    if (A[i] == -1) A[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cout << A[i];
  }
  cout << '\n';
  return 0;
}