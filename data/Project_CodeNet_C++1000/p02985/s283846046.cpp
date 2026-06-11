#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 100000
vector<int>g[MAXN];
ll facs[MAXN+1];

// x^n in mod
ll modpow(ll x, ll n, ll mod){
  if(n==0) return 1;

  if(n%2==0){
    return modpow(x*x%mod, n/2, mod) % mod;
  }else{
    return x * modpow(x, (n-1), mod) % mod;
  }
}

// n! in mod
ll fac(ll n){
  return facs[n];
}

// nCr in mod
ll comb(ll n, ll r){
  if(n<0 || n<r || r<0)return 0;
  ll fn = fac(n);
  ll fr = fac(r);
  ll fn_r = fac(n-r);
  
  ll d = (modpow(fr, MOD-2, MOD) * modpow(fn_r, MOD-2, MOD)) % MOD;
  ll u = fn%MOD;
  
  ll result = u * d % MOD;
 
  return result;
}

// nPr in  mod
ll perm(ll n, ll r){
  if(n<0 || n<r || r<0)return 0;
  ll fn = fac(n);
  ll fn_r = fac(n-r);
  
  ll d = modpow(fn_r, MOD-2, MOD);
  ll u = fn%MOD;
  
  ll result = u * d % MOD;
 
  return result;
}

int n,k;

ll dfs(int node, int pre){
  ll result = 1;
  for(auto nex: g[node]){
    if(nex==pre)continue;

    result = result * dfs(nex, node) % MOD;
  }
  ll ck = pre==-1 ? (ll)k : (ll)(k-2);
  ll child_count = pre==-1 ? (ll)(g[node].size()+1) : (ll)(g[node].size()-1);
  result = result * perm( ck, child_count ) % MOD;
//cout<<node<<' '<<pre<<' '<<result<<endl;
  return result;
}

int main(){
  cin>>n>>k;
  rep(i, n-1){
    int a,b; cin>>a>>b; a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  facs[0]=1;
  rep(i, MAXN)facs[i+1] = (facs[i]*(i+1))%MOD;

  ll result=dfs(0, -1);
  cout<<result<<endl;

  return 0;
}