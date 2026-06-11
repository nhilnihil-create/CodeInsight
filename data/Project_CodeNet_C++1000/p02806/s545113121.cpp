#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define sqr(x) ((x) * (x))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

typedef long long ll;

const int MOD = 1000000007;
const int INF = 1000000007;
const ll INFLL = 1000000000000000007LL;

void solve() {
  int N;
  cin >> N;
  vector<pair<string, int>> pl;
  for (int i = 0; i < N; i++) {
    string s;
    int t;
    cin >> s >> t;
    pl.push_back(make_pair(s, t));
  }
  string X;
  cin >> X;
  int ans = 0;
  bool flag = false;
  for (auto x : pl) {
    if (flag) ans += x.second;
    if (x.first == X) {
      flag = true;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // cout << fixed << setprecision(12);

  solve();

  return 0;
}
