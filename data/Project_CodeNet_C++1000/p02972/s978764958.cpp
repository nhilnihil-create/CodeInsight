#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1);
  a[0] = 0;
  REP(i, N) cin >> a[i + 1];
  vector<int> B(N + 1);
  ll id = N + 1;
  ll num = 0;
  vector<int> hako(0);
  for (ll i = N; i / 2 > N; i--) {
    B[i] = a[i];
    id = i;
    num += B[i];
    if (B[i] == 1) hako.push_back(i);
  }
  for (ll i = id - 1; i >= 1; i--) {
    ll tmp = 0;
    for (ll j = 2; i * j <= N; j++) {
      tmp += B[i * j];
    }
    if (tmp % 2 == a[i]) {
      B[i] = 0;
    } else {
      B[i] = 1;
    }
    num += B[i];
    if (B[i] == 1) hako.push_back(i);
  }
  cout << num << endl;
  REP(i, hako.size()) {
    cout << hako[i] << " ";
    if (i == hako.size() - 1) cout << "\n";
  }
}