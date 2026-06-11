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
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  vector<int> v(n);
  iota(ALL(v), 0);
  double ans = 0;
  int c = 0;
  do {
    c++;
    double temp = 0;
    rep(i,n-1) {
      double d = pow(x[v[i]]-x[v[i+1]], 2) + pow(y[v[i]]- y[v[i+1]], 2);
      temp += sqrt(d);
    }
    ans += temp;
  } while (next_permutation(ALL(v)));
  cout << setprecision(12) << ans / c << endl;
}

int main() {
  solve();
  return 0;
}