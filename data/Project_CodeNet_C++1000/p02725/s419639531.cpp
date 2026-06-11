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
  int k, n;
  cin >> k >> n;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  int temp = k - (v[0] + (k - v[n-1]));
  rep(i,n-1) {
    temp = min(temp, k - (v[i+1] - v[i]));
  }
  cout << temp << endl;
}

int main() {
  solve();
  return 0;
}