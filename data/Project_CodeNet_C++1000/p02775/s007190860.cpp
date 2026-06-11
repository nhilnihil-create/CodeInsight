#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素

vector<vector<int>> dp(1000005, vector<int> (2)); 
int main(){
    string s;
    cin>>s;
    s="0"+s;
    int n=s.size();
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
      int d=s[n-i]-'0';
      dp[i][0]=min(dp[i-1][0]+d,dp[i-1][1]+d+1);
      if(i==1) dp[i][1]=dp[i-1][0]+10-d;
      else dp[i][1]=min(dp[i-1][0]+10-d,dp[i-1][1]+10-(d+1));
    }
    cout<<min(dp[n][0],dp[n][1])<<endl;
    return 0;
}