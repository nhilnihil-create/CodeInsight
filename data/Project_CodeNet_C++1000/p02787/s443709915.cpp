#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[20010];
const int INF=INT_MAX;

int main(){
  int h,n;
  cin>>h>>n;
  vector<P> p(n);
  rep(i,n){
    int a,b;
    cin>>a>>b;
    p[i]=make_pair(a,b);
  }

  for(int i = 1; i <=h+10000; i++){
    dp[i]=INF;
  }
  dp[0]=0;

  for(int damage = 1; damage <=h+10000; damage++){
    rep(i,n){
      int d,c;
      tie(d,c)=p[i];
      if(d > damage) continue;
      if(dp[damage-d]==INF) continue;
      chmin(dp[damage],dp[damage-d]+c);
    }
  }

  int ans = INF;
  for(int i = h; i <= h+10000; i++){
    ans = min(dp[i],ans);
  }
  cout<<ans<<endl;
}
