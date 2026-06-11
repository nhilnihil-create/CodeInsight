#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = ss; i <= ee; ++i)

int N;
void input() { cin >> N; }

void solve() {
  ll ans = 0;
  ll Ni;
  rep(i, 1, N) {
    Ni = N / i;
    ans += i * (Ni * (Ni + 1) / 2);
    // ans += i * (N / i * (N / i + 1) / 2);
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}