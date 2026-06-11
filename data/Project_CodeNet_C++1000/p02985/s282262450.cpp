#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

ll n,k;
ll ans=1;
vec al(1e5+10,-1);
vector<set<ll>> E(1e5+10);

ll mpow(ll x, ll n) {
  ll ans=1;
  while(n>0) {
    if(n&1) {
      ans=ans*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return ans;
}

//階乗,factで初期化
vector<ll> tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

//nCk 繰り返し高速
ll comb(ll n, ll k) {
  return tfact.at(n)*mpow(tfact.at(k),mod-2)%mod*mpow(tfact.at(n-k),mod-2)%mod;
}

//nPk
ll perm(ll n,ll k) {
  return tfact.at(n)*mpow(tfact.at(n-k),mod-2)%mod;
}

void dfs(ll f) {
  ll count=0;
  for(ll t:E[f]) {
    if(al[t]<0) {
      al[t]=0;
      dfs(t);
      count++;
    }
  }
  if(f!=0) {
    if(k-2>0&&k-2>=count) {
      ans=ans*perm(k-2,count)%mod;
    }
    else {
      ans=0;
    }
  }
  else {
    if(k-1>0&&k-1>=count) {
      ans=ans*perm(k-1,count)%mod;
    }
    else {
      ans=0;
    }
  }
}
 
int main() {
  cin >> n >> k;
  if(k==1) {
    if(n==1) {
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }
    return 0;
  }
  if(k==2) {
    if(n<=2) {
      cout << 2 << endl;
    }
    else {
      cout << 0 << endl;
    }
    return 0;
  }
  fact(k);
  for(ll i=0;i<n-1;i++) {
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    E[a].insert(b);
    E[b].insert(a);
  }
  al[0]=0;
  ans=k;
  dfs(0);
  cout << ans << endl;
}