#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const ll mo=998244353;
const int inf=1<<30;

ll rui(ll a,ll n){
  ll ans=1;
  while(n>0){
    if(n&1) ans=ans*a%mo;
    a=a*a%mo;
    n/=2;
  }
  return ans;
}

ll dp[3010][3010];

int main(){
  int n,s; cin >> n >> s;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll ans=0;
  dp[0][0]=1;
  rep(i,n)rep(j,s){
    if(j+a[i]<=3009) dp[i+1][j+a[i]]+=dp[i][j];
    dp[i+1][j]+=dp[i][j]*2;
    dp[i+1][j+a[i]]%=mo;
    dp[i+1][j]%=mo;
  }
  rep(i,n+1){
    ans+=dp[i][s]*rui(2,n-i)%mo;
    ans%=mo;
    //cout << ans << endl;
  }
  /*
  rep(i,n+1){
    rep(j,s+1){
      cout << dp[i][j];
    }cout << endl;
  }
  */
  cout << ans << endl;
}