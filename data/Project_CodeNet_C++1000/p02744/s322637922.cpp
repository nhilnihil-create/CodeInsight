#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define fout(x) cout << fixed << setprecision(10) << x << endl
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

auto print = [](auto &v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
};

int su = 0;
void solve(int n, char c, string s) {
  int sz = s.size();
  if (n == 0) {
    out(s);
    return;
  }
  for (char i = 'a'; i < c; ++i) {
    solve(n - 1, c, s + i);
  }
  solve(n - 1, c + 1, s + c);
  return;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  solve(n, 'a', "");
  return 0;
}
