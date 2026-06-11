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
  ll h, w;
  cin >> h >> w;
  if (h == 1 || w == 1) cout << 1 << endl;
  else cout << h * w / 2 + ((h*w)% 2);
}

int main() {
  solve();
  return 0;
}