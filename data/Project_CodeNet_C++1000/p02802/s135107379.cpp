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
  int n, m;
  cin >> n >> m;
  vector<int> p(m);
  vector<string> s(m);
  rep(i,m) cin >> p[i] >> s[i];
  vector<int> wa(n);
  vector<int> ac(n);
  rep(i,m) {
    if (ac[p[i]-1]) continue;
    if (s[i] == "WA") wa[p[i]-1]++;
    else ac[p[i]-1]++;
  }
  int cwa = 0;
  int cac = 0;
  rep(i,n) {
    if (ac[i]) {
      cac++;
      cwa += wa[i];
    }
  }
  cout << cac << " " << cwa << endl;
}

int main() {
  solve();
  return 0;
}