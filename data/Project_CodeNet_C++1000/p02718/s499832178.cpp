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
  rep(i, N) cin >> A[i];
  int total = 0;
  rep(i, N) total += A[i];
  int cnt = 0;
  rep(i, N) {
    if (A[i] * 4 * M >= total) cnt++;
  }
  bool bl = cnt >= M;
  puts(bl ? "Yes" : "No");
  return 0;
}