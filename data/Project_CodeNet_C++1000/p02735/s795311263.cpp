#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[110][110][2];

int dx[2]={1,0};
int dy[2]={0,1};

int main()
{
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i, H) cin >> A[i];
  REP(i,H){
    REP(j,W){
      REP(k,2){
        dp[i][j][k]=INF;
      }
    }
  }
  if(A.at(0).at(0)=='#'){
    dp[0][0][1]=1;
  }
  if(A.at(0).at(0)=='.'){
    dp[0][0][0]=0;
  }
  REP(i,H){
    REP(j,W){
      REP(k,2){
        if(i+dy[k]>=H||j+dx[k]>=W) continue;
        if(A.at(i+dy[k]).at(j+dx[k])=='.'&&A.at(i).at(j)=='.'){
          chmin(dp[i+dy[k]][j+dx[k]][0],dp[i][j][0]);
        }
        if(A.at(i+dy[k]).at(j+dx[k])=='#'&&A.at(i).at(j)=='.'){
          chmin(dp[i+dy[k]][j+dx[k]][1],dp[i][j][0]+1);
        }
        if(A.at(i+dy[k]).at(j+dx[k])=='.'&&A.at(i).at(j)=='#'){
          chmin(dp[i+dy[k]][j+dx[k]][0],dp[i][j][1]);
        }
        if(A.at(i+dy[k]).at(j+dx[k])=='#'&&A.at(i).at(j)=='#'){
          chmin(dp[i+dy[k]][j+dx[k]][1],dp[i][j][1]);
        }
      }
    }
  }

  if(A.at(H-1).at(W-1)=='#'){
    cout << dp[H-1][W-1][1] << endl;
  }else if(A.at(H-1).at(W-1)=='.'){
    cout << dp[H-1][W-1][0] << endl;
  }
}