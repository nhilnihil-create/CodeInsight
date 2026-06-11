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

vvl G;
vl ans;
vector<bool> B;
queue<P> q;

int main() {
  ll N,M;
  cin >> N >> M;
  G.resize(3*N);
  ans.assign(3*N,0);
  B.assign(3*N,false);
  rep(i,M){
    //移動回数をmod3でわける、0=>a,1=>n+a,2=>2n+a
    ll a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(N+b);
    G[a+N].push_back(2*N+b);
    G[a+2*N].push_back(b);
  }
  ll S,T;
  cin >> S >> T;
  S--;T--;
  q.push(make_pair(S,0));
  ans[S]=0;
  B[S]=true;
  while(!q.empty()){
    ll x=q.front().first;
    ll y=q.front().second;
    q.pop();
    ll k=G[x].size();
    rep(i,k){
      if(B[G[x][i]]==false){
        ans[G[x][i]]=y+1;
        q.push(make_pair(G[x][i],y+1));
        B[G[x][i]]=true;
      }
    }
  }
  
  if(ans[T]!=0){
    cout << ans[T]/3 << endl;
  }
  else{
    cout << -1 << endl;
  }
}