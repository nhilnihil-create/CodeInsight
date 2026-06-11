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

int dp[3005][3005];

int main(){
  int n,t;
  cin >> n >> t;
  vector<P> v(n);
  rep(i,n){
    int a,b;
    cin >> a >> b;
    v[i]=P(a,b);
  }
  sort(v.begin(),v.end());
  rrep(i,n){
    rep(j,t){
      chmax(dp[i][j],dp[i-1][j]);
      if(j-v[i-1].first>=0)chmax(dp[i][j],dp[i-1][j-v[i-1].first]+v[i-1].second);
    }
  }
  int ans = 0;
  rep(i,n){
    chmax(ans,dp[i][t-1]+v[i].second);
  }
  cout << ans << endl;
}