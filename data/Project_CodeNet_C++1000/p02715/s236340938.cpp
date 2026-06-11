/*
         ██╗ ██████╗ ██╗███╗   ██╗    ██╗   ██╗███████╗
         ██║██╔═══██╗██║████╗  ██║    ██║   ██║██╔════╝
         ██║██║   ██║██║██╔██╗ ██║    ██║   ██║███████╗
    ██   ██║██║   ██║██║██║╚██╗██║    ██║   ██║╚════██║
    ╚█████╔╝╚██████╔╝██║██║ ╚████║    ╚██████╔╝███████║
     ╚════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝     ╚═════╝ ╚══════╝
*/
//password:+BdCHpO8dQvpo5fnV3/u
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 5e5 + 6;
const int inf = 0x3f3f3f3f;
const ll mod=1e9+7;
ll prime[maxn],v[maxn],phi[maxn];
ll sphi[maxn];
ll m=0;
void euler(ll n){
  memset(v,0,sizeof(v));
  m=0;
  for(ll i=2;i<=n;i++){
    if(v[i]==0){
      v[i]=i;
      prime[++m]=i;
      phi[i]=i-1;
    }
    // cout<<i<<"\n";
    for(ll j=1;j<=m;j++){
      if(prime[i]>v[i]||prime[j]>n/i) break;
      v[i*prime[j]]=prime[j];
      phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
     }
  }
  phi[1]=1;
  for(ll i=1;i<=n;i++)
  sphi[i]=(sphi[i-1]+phi[i])%mod;
}
inline ll mpow(ll a,ll n){
  ll ans=1%mod;
  while(n){
    if(n&1) ans=ans*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return ans;
}
map<ll,ll>sp;
inline ll getphi(ll n){
  if(n<maxn) return sphi[n];
  if(sp.count(n)) return sp[n];
   ll ret = 1ll * n * (n + 1) %mod;
   ret=ret*mpow(2,mod-2)%mod;
   for(ll l = 2, r; l <= n; l = r + 1) {
    r = n / (n / l); ret =(ret- (r - l + 1) * getphi(n / l)%mod+mod)%mod;
    // 同上，因为两个的 g 都是 I 
  } return sp[n] = ret; // 记忆化
}

inline ll solve(ll n,ll k){
  long long res = 0, pre = 0, cur;
  for (long long i = 1, j; i <= k; i = j + 1){
    j = k / (k / i),pre=getphi(i-1),cur = getphi(j),
    //  cout<<mpow(k/i,n)<<" "<<cur - pre<<"#";cout<<i<<" "<<j<<"\n";
    res = (res + (mpow(k/i,n) * (cur - pre)%mod) % mod) % mod, pre = cur;
  }
  return (res + mod) % mod;
}


int main() {
  euler(500005);
  // cout<<1<<"\n";
  ll n,k;
  scanf("%lld%lld",&n,&k);
  printf("%lld\n",solve(n,k));
  return 0;
}