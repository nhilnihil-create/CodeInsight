#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

int dp[100010][15];
signed main(){
  string s;cin>>s;
  int n=s.length();
  dp[0][0]=1;
  rep(i,n){
    if(s[i]!='?'){
      int x=s[i]-'0';
      rep(j,13){
        dp[i+1][(10*j+x)%13]=dp[i][j];
      }
    }
    else{
      rep(x,10){
        rep(j,13){
          (dp[i+1][(10*j+x)%13]+=dp[i][j])%=MOD;
        } 
      }
    }
  }
  cout<<dp[n][5]<<endl;
  return 0;
}