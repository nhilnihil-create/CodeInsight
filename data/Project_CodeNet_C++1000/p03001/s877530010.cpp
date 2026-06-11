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
  ll w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << setprecision(15) << w * h / 2.0 << " " << ((w / 2.0 == x && h / 2.0 == y)? 1: 0) << endl;
}

int main() {
  solve();
  return 0;
}