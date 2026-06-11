#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int K; cin >> K;
  ll ans = 0;
  ll dp[10][11];
  rep(i,10) dp[i][1] = 1;

  for (int l=1;l<=10;l++){
    for (int t=0;t<10;t++){
      if (t==0) dp[t][l+1] = dp[t][l] + dp[t+1][l];
      else if (t==9) dp[t][l+1] = dp[t][l] + dp[t-1][l];
      else dp[t][l+1] = dp[t-1][l] + dp[t][l] + dp[t+1][l];
    }
  }
  int idx = 0;
  bool flag = false;
  int top, len;
  for (int l=1;l<=10;l++){
    for (int t=1;t<10;t++){
      if (idx+dp[t][l]>=K) {
        flag = true;
        top = t, len = l;
        break;
      }
      idx += dp[t][l];
    }
    if (flag) break;
  }

  vector<int> digit;
  digit.push_back(top);
  while (len>1){
    int tmp = 0;
    int to[3] = {-1,0,1};
    rep(i,3){
      if (top+to[i]<0 || top+to[i]>9) continue;
      if (idx+dp[top+to[i]][len-1]>=K) {
        top = top+to[i];
        digit.push_back(top);
        len--;
        break;
      }
      idx += dp[top+to[i]][len-1];
    }

  }
  rep(i, digit.size()) cout << digit[i];
  cout << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}
