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
  ll n;
  cin >> n;
  ll a, b;
  cin >> a >> b;
  if ((b - a) % 2 == 0) {
    cout << (b - a) / 2 << endl;
  } else {
    cout << min(a - 1, n - b) + 1 + (b - a - 1) / 2 << endl;
  }
}

int main() {
  solve();
  return 0;
}