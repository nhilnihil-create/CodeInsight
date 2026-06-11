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
  int n, k, s;
  cin >> n >> k >> s;
  rep(i,k) cout << s << " ";
  rep(i,n-k) {
    if (s == INF) {
      cout << 1 << " ";
    } else {
      cout << s + 1 << " ";
    }
  }
  cout << endl;
}

int main() {
  solve();
  return 0;
}