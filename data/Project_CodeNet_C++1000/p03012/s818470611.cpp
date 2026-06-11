#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const ll INF = 1E+15;

int main(){
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) {
    int x;
    cin >> x;
    if (i==0) s[i] = x;
    else s[i] = s[i-1] + x;
  }
  int ans = 10000000;
  rep(i, n) {
    ans = min(ans, abs(s[n-1]-2*s[i]));
  }
  cout << ans << endl;
  return 0;
}