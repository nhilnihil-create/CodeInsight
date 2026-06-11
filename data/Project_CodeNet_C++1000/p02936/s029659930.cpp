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

const ll MXN=200000;
vl G[MXN];
vl B(MXN,0),d(MXN,0),ans(MXN,0);

void bfs(ll x,ll p){
  ans[x]=p;
  B[x]=1;
  rep(i,(ll)G[x].size()){
    if(B[G[x][i]]==0){
      bfs(G[x][i],p+d[G[x][i]]);
    }
  }
}
int main() {
  ll N,Q;
  cin >> N >> Q;
  rep(i,N-1){
    ll a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i,Q){
    ll p,x;
    cin >> p >> x;
    p--;
    d[p]+=x;
  }
  bfs(0,d[0]);
  rep(i,N){
    cout << ans[i] << endl;
  }
}