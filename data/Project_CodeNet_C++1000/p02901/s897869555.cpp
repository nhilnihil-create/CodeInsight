#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int dp[1005][5000];

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> di(m);
  vector<int> a(m);
  rep(i, m){
    int b;
    cin >> a[i] >> b;
    rep(j, b){
      int c;
      cin >> c;
      c--;
      di[i]+=(1<<c);
    }
  }
  rep(i, m+1)rep(j, (1<<n)){
    dp[i][j]=INF;
  }
  rep(i, m+1){
    dp[i][0]=0;
  }

    rep(j, (1<<n)){
      rep(i, m){
      /*
      if(i+1==3 && (di[i]|j)==3){
        cout << di[i] << endl;
        cout << j << endl;
        cout << (di[i]|j) << endl;
        cout << dp[i+1][(di[i]|j)] << " " << dp[i][j]+a[i] << endl;
      }
      */
      dp[i+1][(int)(di[i]|j)]=min(dp[i+1][(int)(di[i]|j)], dp[i][j]+a[i]);
      dp[i+1][j]=min(dp[i][j], dp[i+1][j]);
      //dp[i+1][di[i]|j]=min(dp[i+1][di[i]|j], dp[i][di[i]|j]);
    }
  }
  if(dp[m][(int)((1<<n)-1)]==INF){
    cout << "-1" << endl;
  } else {
      cout << dp[m][(int)((1<<n)-1)] << endl;
  }

  return 0;
}
