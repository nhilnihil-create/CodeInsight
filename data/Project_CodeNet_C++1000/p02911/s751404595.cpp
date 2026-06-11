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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> v(n, k - q);
  rep(i,q) {
    int a;
    cin >> a;
    a--;
    v[a]++;
  }
  rep(i,n) {
    if (v[i] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

int main() {
  solve();
  return 0;
}