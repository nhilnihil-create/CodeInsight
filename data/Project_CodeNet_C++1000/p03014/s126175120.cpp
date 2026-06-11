#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll H,W;
  cin >> H >> W;
  vvc s(H,vc(W));
  rep(i,H){
    rep(j,W){
      cin >> s[i][j];
    }
  }
  vvl a(H,vl(W)),b(H,vl(W));
  rep(i,H){
    rep(j,W){
      ll cnt=0;
      if(s[i][j]=='#'){
        a[i][j]=0;
      }
      else{
        if(j==0||(j!=0&&s[i][j-1]=='#')){
          cnt=0;
          ll nj=j;
          while(nj<W&&s[i][nj]=='.'){
            cnt++;
            nj++;
          }
          a[i][j]=cnt;
        }
        else{
          a[i][j]=a[i][j-1];
        }
      }
    }
  }
  rep(j,W){
    rep(i,H){
      ll cnt=0;
      if(s[i][j]=='#'){
        b[i][j]=0;
      }
      else{
        if(i==0||(i!=0&&s[i-1][j]=='#')){
          cnt=0;
          ll ni=i;
          while(ni<H&&s[ni][j]=='.'){
            cnt++;
            ni++;
          }
          b[i][j]=cnt;
        }
        else{
          b[i][j]=b[i-1][j];
        }
      }
    }
  }
  ll ans=0;
  rep(i,H){
    rep(j,W){
      if(s[i][j]=='.'){
        ans=max(ans,a[i][j]+b[i][j]-1);
      }
    }
  }
  cout << ans << endl;
}