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

int h, w;
int vcnt[2020][2020];
int hcnt[2020][2020];

int main() {
  cin >> h >> w;
  vector<vector<char>> v(h+2,vector<char>(w+2,'#'));
  rep(i,h)rep(j,w) cin >> v[i+1][j+1];
  rep(i,h) {
    int cnt = 0;
    rep(j,w+1) {
      if(v[i+1][j+1]=='.') cnt++;
      else if(v[i+1][j]=='.') {
        for(int k = j-cnt+1; k<=j; k++) hcnt[i+1][k] = cnt;
        cnt = 0;
      }
    }
  }
  rep(i,w) {
    int cnt = 0;
    rep(j,h+1) {
      if(v[j+1][i+1]=='.') cnt++;
      else if(v[j][i+1]=='.') {
        for(int k = j-cnt+1; k<=j; k++) vcnt[k][i+1] = cnt;
        cnt = 0;
      }
    }
  }
  int ans = 0;
  rep(i,h)rep(j,w) {
    int tmp = hcnt[i+1][j+1] + vcnt[i+1][j+1] - 1;
    ans = max(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}