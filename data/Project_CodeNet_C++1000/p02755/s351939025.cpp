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
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= 1010; i++) {
    if (((int)(0.08 * i)) == a && ((int)(0.10 * i)) == b) {
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