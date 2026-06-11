#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = ss; i < ee; ++i)

ll N;
vector<ll> v;

void input() {
  cin >> N;
  v.resize(N);
  for (auto &e : v) { cin >> e; }
  sort(v.rbegin(), v.rend());
}

void solve() {
  ll ans = v.front();
  ll t = (N - 1) - 1;//全回数(n-1)-1最初の1回
  ll i = 1;
  bool cnt2 = false;//降順要素を各2回づつ加算
  while (t > 0) {
    ans += v[i];
    if (cnt2) {
      i++;
      cnt2 = false;
    } else {
      cnt2 = true;
    }
    t--;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
}
