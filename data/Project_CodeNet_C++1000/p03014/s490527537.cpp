#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  rep(i,h) cin >> v[i];

  vector<vector<int>> a(h);
  vector<vector<int>> b(w);

  rep(i,h) {
    int count = 0;
    rep(j,w) {
      if (v[i][j] == '.') count++;
      else {
        rep(k,count) a[i].push_back(count);
        a[i].push_back(0);
        count = 0;
      }
    }
    rep(k,count) a[i].push_back(count);
  }
  rep(i,w) {
    int count = 0;
    rep(j,h) {
      if (v[j][i] == '.') count++;
      else {
        rep(k,count) b[i].push_back(count);
        b[i].push_back(0);
        count = 0;
      }
    }
    rep(k,count) b[i].push_back(count);
  }

  int ans = 0;
  rep(i,h) {
    rep(j,w) {
      ans = max(ans, a[i][j] + b[j][i] - 1);
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}