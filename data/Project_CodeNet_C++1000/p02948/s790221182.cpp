#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> pq;
  vector<vi> v(110000);
  rep(i,n) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
  }
  int ans = 0;
  for(int i = 1; i<=m; i++) {
    rep(j,v[i].size()) pq.push(v[i][j]);
    if(!pq.empty()) {
      int k = pq.top();
      ans += k;
      pq.pop();
    }
  }
  cout << ans << endl;
  return 0;
}