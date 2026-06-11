#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,w,a,b; cin >> h >> w >> a >> b;
  vector<vi> ans(h,vi(w));

  rep(i,b) rep(j,w-a) ans[i][j+a] = 1;
  rep(i,h-b) rep(j,a) ans[i+b][j] = 1;

  bool res = true;
  rep(i,w){
    int cnt = 0;
    rep(j,h) cnt += ans[j][i];
    if(b != min(cnt,h-cnt)) res = false;
  }
  rep(i,h){
    int cnt = 0;
    rep(j,w) cnt += ans[i][j];
    if(a != min(cnt,w-cnt)) res = false;
  }
  if(res){
    rep(i,h){
      rep(j,w) cout << ans[i][j];
      cout << endl;
    }
  }else cout << "No\n";
  // cout << "\n";
  return 0;
}
