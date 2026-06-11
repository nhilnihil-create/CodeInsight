#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;

int main(){
  int H, W; cin >> H >> W;
  string S[H];
  rep(i,H) cin >> S[i];
  vector<vector<int>> n(H,vector<int>(W,0));
  
  rep(i,H) {
    int cnt = 0;
    rep(j,W){
      if (S[i][j]=='.' && cnt==0){
        int j0 = j;
        while (j0<W && S[i][j0]=='.') cnt++, j0++;
        n[i][j] = cnt;
      }
      else if (S[i][j]=='.') n[i][j] = cnt;
      else cnt = 0;
    }
  }

  rep(j,W) {
    int cnt = 0;
    rep(i,H){
      if (S[i][j]=='.' && cnt==0){
        int i0 = i;
        while (i0<H && S[i0][j]=='.') cnt++, i0++;
        n[i][j] += cnt;
      }
      else if (S[i][j]=='.') n[i][j] += cnt;
      else cnt = 0;
    }
  }

  int ans = 0;
  rep(i,H) rep(j,W) chmax(ans, n[i][j]);
  cout << ans-1 << endl;


  
  // cout << fixed << setprecision(10);
  
  return 0;
}
