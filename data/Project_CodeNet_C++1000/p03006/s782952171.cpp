#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi x(n),y(n); rep(i,n) cin >> x[i] >> y[i];
  int ans = INF;
  rep(i,n){
    rep(j,n){
      int cnt = 0;
      ll p = x[i]-x[j], q = y[i]-y[j];
      if(p != 0 || q != 0) rep(k,n) rep(l,n) if(x[k]-x[l] == p && y[k]-y[l] == q) cnt++;
      chmin(ans,n-cnt);
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
