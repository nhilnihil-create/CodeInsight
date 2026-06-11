  #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define ll  long long
  #define ld long double
  #define pb push_back
  #define mp3 make_pair
  #define rep1(i,a,b) for(ll i=a;i<=b;i++)
  #define rep2(i,a,b) for(ll i=a;i<b;i++)
  const ll  mod=998244353;
  const ll INF=1e18;
  template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
  template<typename T> T add(T a,T b,ll m){a+=b;while(a>=0)a-=m;while(a<0)a+=m; return a;}
  template<typename T> T mul(T a,T b,ll m){return (a*1ll*b)%m;}
  int main(){
    IOS;
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll x=a*c;
    ll y=b*c;
    ll z=a*d;
    ll w=b*d;
    cout<<max(x,max(y,max(z,w)));
  }