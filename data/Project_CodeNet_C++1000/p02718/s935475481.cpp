#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N, M, cnt;
  cin >> N >> M;
  vector<int> a(N);
  rep(i, N) cin >> a.at(i);
  int sum = 0;
  rep(i, N) sum += a.at(i);
  rep(i, N) {
    if (a.at(i) * 4 * M >= sum) cnt++;
  }
  if (cnt >= M) cout << "Yes" << endl;
  else cout << "No" << endl;
}