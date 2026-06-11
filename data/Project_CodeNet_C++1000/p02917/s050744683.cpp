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
  vector<int> b(n-1);
  rep(i,n-1) cin >> b[i];
  vector<int> ans(n+1);
  ans[0] = b[0];
  ans[n] = b[n-2];
  rep(i,n-2) {
    ans[i+1] = min(b[i], b[i+1]);
  }
  int res = 0;
  for(int i: ans) res += i;
  cout << res << endl;
}

int main() {
  solve();
  return 0;
}