#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmin(x,y) x = min(x,y)

ll mod = 1000000007;
ll modsize = 100010;
vector<ll> fac(modsize);
vector<ll> inv(modsize);
vector<ll> facinv(modsize);

void modcalc(){
    if(modsize == 0) abort();
    fac[0] = 1; fac[1] = 1; inv[1] = 1;
    facinv[0] = 1; facinv[1] = 1;
    for(ll i = 2 ; i < modsize ; i++){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        facinv[i] = facinv[i-1] * inv[i] % mod;
    }
}

ll modinv(ll a){
    if(a==0) abort();
    ll b = mod, u = 1, v = 0;
    while(b){
        ll t = a/b;
        a -= t * b; swap(a,b);
        u -= t * v; swap(u,v);
    }
    u %= mod;
    if(u<0) u += mod;
    return u;
}

ll modpow(ll a,ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll modcomb(ll n, ll k){
    if(n<0||k<0||n<k) return 0;
    return fac[n] * facinv[k] % mod * facinv[n-k] % mod;
}

ll modperm(ll n, ll k){
    if(n<0||k<0||n<k) return 0;
    return fac[n] * facinv[n-k] % mod;
}

ll modhom(ll n, ll k){
    if(n<0||k<0||(n==0&&k>0)) return 0;
    if(n==0&&k==0) return 1;
    return fac[n+k-1] * facinv[k] % mod * facinv[n-1] % mod;
}

ll n,k,ans;
vector<ll> to[100005];
void dfs(int v,int p=-1){
    for(int u : to[v]){
        if(u==p) continue;
        dfs(u,v);
    }
    int a = (p==-1) ? k : k-2;
    int b = (p==-1) ? to[v].size()+1 : to[v].size()-1;
    ans *= modperm(a,b);
    ans %= mod;
}

int main(){
    cin>>n>>k;
    modcalc();
    rep(i,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans = 1;
    dfs(0);
    cout << ans << endl;
}