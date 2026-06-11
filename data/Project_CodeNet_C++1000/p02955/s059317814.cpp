#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

// ====================================================================

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  ll gokei = accumulate(v.begin(), v.end(), 0ll);

  vector<ll> yakusu;  // 約数を入れる
  for (ll g = 1; g * g <= gokei; g++)
    if (gokei % g == 0) yakusu.push_back(g), yakusu.push_back(gokei / g);
  sort(yakusu.begin(), yakusu.end());

  ll ans = -1;
  for (auto x : yakusu) {
    vector<ll> r;  // xで割った余りを入れる
    for (int i = 0; i < n; i++)
      if (v[i] % x != 0) r.push_back(v[i] % x);
    sort(r.begin(), r.end());
    if (r.size() == 0) ans = max(ans, x);  // 手を付けずともokならok
    // cout << x << " " << r << " ---------" << endl;
    ll shita = accumulate(r.begin(), r.end(), 0);  // 全てを0にするとき
    ll ue = 0;
    for (int i = r.size() - 1; i >= -1; i--) {
      // cout << shita << " " << ue << endl;
      if (abs(shita - ue) % x == 0 && ue + abs(shita - ue) <= k) {  // これならいける
        ans = max(ans, x);
      }
      if (i < 0) break;
      ue += x - r[i];  // 上側にずらすとする
      shita -= r[i];
    }
  }

  cout << ans << endl;
}
