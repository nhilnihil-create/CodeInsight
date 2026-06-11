#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  ll ans = 0;
  map<int, int> m;
  rep(i, N) {
    ans += m[A[i]];
    m[A[i]]++;
  }

  rep(i, N) { cout << ans - m[A[i]] + 1 << endl; }
}