  #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define ll  long long
  #define ld long double
  #define pb push_back
  #define mp3 make_pair
  #define rep1(i,a,b) for(ll i=a;i<=b;i++)
  #define rep2(i,a,b) for(ll i=a;i<b;i++)
  const ll  mod=1e9+7;
  const ll INF=1e18;
  template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
  template<typename T> T add(T a,T b,ll m){a+=b;while(a>=0)a-=m;while(a<0)a+=m; return a;}
  template<typename T> T mul(T a,T b,ll m){return (a*1ll*b)%m;}
  ll sum;
  ll dp[1000000];
  ll rec(ll x){
    if(x==0)
    return 1;
    if(x<0)
    return 0;
    if(dp[x]!=-1)
    return dp[x];
    ll ans=0;
    for(ll i=3;i<=x;i++){
      ans=add(ans,rec(x-i)%mod,mod);
    }
    return dp[x]=ans;
  }
  int main(){
    IOS;
    cin>>sum;
    memset(dp,-1,sizeof(dp));
    cout<<rec(sum);
  } 