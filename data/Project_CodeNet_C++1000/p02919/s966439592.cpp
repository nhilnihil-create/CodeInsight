#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) { cin >> v[i]; }

  vector<int> pos(n + 1);  // それぞれの数字がどこにあるか？
  for (int i = 0; i < n; i++) pos[v[i]] = i;

  ll ans = 0;
  multiset<int> st = {-1, -1, n, n};  // 自分より大きいやつの位置
  for (ll i = n; i > 0; i--) {
    st.insert(pos[i]);

    // for (auto x : st)
    //   cout << x << " ";
    // cout << endl;

    auto now = st.lower_bound(pos[i]);
    // 左側を含むやつ
    // cout << "prev " << *now << " " << *prev(now, 1) << " " << *prev(now, 2) << endl;
    ans += i * (*prev(now, 1) - *prev(now, 2)) * (*next(now, 1) - *now);
    // 右側を含むやつ
    ans += i * (*now - *prev(now, 1)) * (*next(now, 2) - *next(now, 1));
    // cout << i << " " << ans << endl;
  }
  cout << ans << endl;
}
