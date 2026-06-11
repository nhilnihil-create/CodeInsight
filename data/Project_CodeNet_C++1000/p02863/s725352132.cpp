#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
// int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,t;
  cin >> n >> t;
  vector<pair<int,int>>ab;
  rep(i,n){
    int A,B;
    cin >> A >> B;
    ab.push_back(make_pair(A,B));
  }
  sort(ab.begin(),ab.end());
  
  ll dp[3030][3030]={};
  ll ans = 0;
  rep(i,n){
    rep(j,t){
      dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
      if(j+ab[i].first<t)dp[i+1][j+ab[i].first]=max(dp[i+1][j+ab[i].first],dp[i][j]+ab[i].second);
    }
    ans=max(ans,dp[i][t-1]+ab[i].second);
  }
  cout << ans << endl;
  return 0;
}
