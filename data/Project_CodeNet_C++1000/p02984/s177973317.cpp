#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=acos(-1);
const ll INF=1e15;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

const ll MXN=300000;
vl G[MXN];
vl ans(MXN,0);
vl d(MXN,0);

void dfs(ll x,ll y){
  ans[x]=y;
  ll k=G[x].size();
  if(k!=0){
    rep(i,k){
      if(ans[G[x][i]]==0){
        dfs(G[x][i],y+d[G[x][i]]);
      }
    }
  }
}

int main() {
  ll N;
  cin >> N;
  vl a(N);
  ll x;
  rep(i,N){
    cin >> a[i];
    if(i%2==1){
      x-=a[i];
    }
    else{
      x+=a[i];
    }
  }
  rep(i,N){
    if(i==0){
      cout << x << endl;
    }
    else{
      cout << 2*a[i-1]-x << endl;
      x=2*a[i-1]-x;
    }
  }
}