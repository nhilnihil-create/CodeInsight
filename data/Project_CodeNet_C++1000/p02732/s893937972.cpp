#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> cnt(200001, 0);
  ll ans = 0;
  rep(i, N) {
    cin >> A.at(i);
    ans += cnt.at(A.at(i));
    cnt.at(A.at(i))++;
  }

  rep(i, N) cout << ans - cnt.at(A.at(i)) + 1 << endl;
}
