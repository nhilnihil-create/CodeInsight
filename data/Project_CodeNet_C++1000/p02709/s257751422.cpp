#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#define ALL(p) (p).rbegin(),(p).rend()
using namespace std;
typedef long long ll;
int main(){
  ll i,j,n,x,y,result;
  ll a;
  map<ll,ll> dp[2010];
  //dp[i][j]: i人を配置し、うち左にj人、右にi-j人いるときのmax
  cin >> n;
  vector<pair<ll,ll> > p(n+1);
  for(i=0;i<n;i++){
    cin >> p[i].first;
    p[i].second = i;
  }
  sort(ALL(p));
  
  for(i=0;i<n;i++){
    a = p[i].first;
    j = p[i].second;
    for(x=0;x<=i;x++){
      if(dp[i][x]>=0){
        dp[i+1][x+1] = max(dp[i+1][x+1],dp[i][x]+a*abs(j-x));
        dp[i+1][x] = max(dp[i+1][x],dp[i][x]+a*abs(n-1-(i-x)-j));
      }
    }
  }
  result=dp[n][0];
  for(i=1;i<=n;i++) result = max(result,dp[n][i]);
  cout << result << endl;
  
  return 0;
}