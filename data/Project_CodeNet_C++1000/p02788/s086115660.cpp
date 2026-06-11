#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[])
{
  int n;

  ll d, a;
  cin >> n >> d >> a;
  vector<pair<ll, ll>> monsters(n);
  for (auto &m : monsters) {
    cin >> m.first >> m.second;
  }

  sort(monsters.begin(), monsters.end());
  ll ans = 0;
  ll c_damage = 0;
  vector<ll> expire(n, 0);
  for (int i = 0; i < monsters.size(); i++) {
    c_damage -= expire[i];
    monsters[i].second = max(monsters[i].second - c_damage, 0ll);

    // どこまでダメージが及ぶか
    auto right_it = upper_bound(monsters.begin(), monsters.end(),
        monsters[i].first + 2 * d,
        [](int r, auto &monster) { return monster.first > r; });
    int right_idx = distance(monsters.begin(), right_it);
    
    // 右まで来たら期限切れ
    ll use_times = (monsters[i].second + a - 1) / a;
    ll damage = use_times * a;
    c_damage += damage;
    ans += use_times;
    if (right_it != monsters.end()) {
      expire[right_idx] += damage;
    }
  }

  cout << ans << "\n";
  return 0;
}