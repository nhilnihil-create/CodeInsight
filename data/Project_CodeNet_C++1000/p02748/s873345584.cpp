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

void solve() {
  int na, nb, m;
  cin >> na >> nb >> m;
  vector<int> a(na), b(nb);
  rep(i,na) cin >> a[i];
  rep(i,nb) cin >> b[i];
  vector<int> x(m), y(m), c(m);
  rep(i,m) cin >> x[i] >> y[i] >> c[i];
  rep(i,m) x[i]--, y[i]--;
  int ans = INF;
  rep(i,m) {
    ans = min(ans, a[x[i]] + b[y[i]] - c[i]);
  }
  sort(ALL(a));
  sort(ALL(b));
  ans = min(ans, a[0] + b[0]);
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}