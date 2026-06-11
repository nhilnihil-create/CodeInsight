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
  ll N;
  cin >> N;
  ll ans=N;
  vl x(N),y(N);
  rep(i,N){
    cin >> x[i] >> y[i];
  }
  rep(i,N){
    rep(j,N){
      if(i==j){
        continue;
      }
      else{
        ll cnt=0;
        ll dx=x[i]-x[j],dy=y[i]-y[j];
        rep(I,N){
          rep(J,N){
            if(I==J){
              continue;
            }
            else{
              if(x[I]-x[J]==dx&&y[I]-y[J]==dy){
                cnt++;
              }
            }
          }
        }
        ans=min(ans,N-cnt);
      }
    }
  }
  cout << ans << endl;
}