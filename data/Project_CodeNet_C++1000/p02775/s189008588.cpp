#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int dp[1000005][2];

int main(){
  string s;
  cin >> s;
  int n = s.size()+1;
  reverse(s.begin(),s.end());
  s += '0';
  rep(i,n+3)rep(j,2)dp[i][j]=INF;
  dp[0][0]=0;
  for(int i=0;i<n;i++)rep(j,2){
    int nd = s[i]-'0';
    if(j==1)nd++;
    rep(d,10){
      if(d>=nd){
        dp[i+1][0]=min(dp[i+1][0],dp[i][j]+d+d-nd);
      }else{
        dp[i+1][1]=min(dp[i+1][1],dp[i][j]+d+d+10-nd);
      }
    }
  }
  cout << dp[n][0] << endl;
}