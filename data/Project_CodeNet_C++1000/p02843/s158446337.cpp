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
  if (n < 100) {
    cout << 0 << endl;
    return;
  }
  int h = n/100;
  int d = n%100;
  if (h*5<d) cout << 0 << endl;
  else cout << 1 << endl;
}

int main() {
  solve();
  return 0;
}