#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int keta(int x) {
  if (x == 0) return 0;
  return 1 + keta(x / 10);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m), c(m);
  rep(i,m) cin >> s[i] >> c[i];
  for (int i = 0; i < 1000; i++) {
    string t = to_string(i);
    if (t.size() != n) continue;
    bool b = true;
    rep(j,m) {
      if (t[s[j] - 1] != (char) c[j] + '0') b = false;
    }
    if (b) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
}

int main() {
  solve();
  return 0;
}