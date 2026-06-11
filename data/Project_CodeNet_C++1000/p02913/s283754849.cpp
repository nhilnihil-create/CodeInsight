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
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int dp[5005][5005];

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  dp[0][0]=0;
  rrep(i,n){
    rrep(j,n){
      if(i<=j)continue;
      if(s[i-1]==s[j-1])dp[i][j]=dp[i-1][j-1]+1;
    }
  }
  int ans = 0;
  rrep(i,n){
    rrep(j,n){
      if(i<=j)continue;
      chmax(ans,min(dp[i][j],i-j));
    }
  }
  cout << ans << endl;
}