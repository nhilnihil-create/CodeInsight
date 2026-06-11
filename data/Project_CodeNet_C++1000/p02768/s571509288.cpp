#include <bits/stdc++.h>
#define ll long long int
#define FASTIO std::ios::sync_with_stdio(false);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define inf 1e18
#define g(x) cout<<x<<" "<<endl;
#define gg(x,y) cout<<x<<" & "<<y<<" "<<endl
#define jam(t) cout<<"Case #"<<t<<": "
#define ggg(x,y,z) cout<<x<<" & "<<y<<" & "<<z<<" "<<endl
#define all(x) x.begin(),x.end()
#define input_from_file  freopen("input.txt", "r", stdin);
#define mod 1000000007ll
#define sz 400005
#define bitcnt(x) __builtin_popcountll(x)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    Combo() {
        fac[0] = ifac[0] = 1;
        for(ll i=1;i< (SZ+1);i++) {
            fac[i] = i*fac[i-1] % mod;
            ifac[i] = inv(fac[i]);
        }
    }
    
    ll po (ll b, ll p) {
        return !p?1:po(b*b%mod,p/2)*(p&1?b:1)%mod;
    }
    
    ll inv (ll b) { return po(b,mod-2); }
    
    ll comb(ll a, ll b) {
        if (a < b) return 0;
        ll tmp = fac[a]*ifac[b] % mod;
        tmp = tmp*ifac[a-b] % mod;
        return tmp;
    }
};
Combo <1000000> C;

ll get(ll n,ll x){
    ll re = 1;
    for(ll j=0;j<x;j++){
        re*=(n-j);
        re%=mod;
    }
    re*=C.ifac[x];
    re%=mod;
    return re;
}
void solve(){
    ll n,a,b;
    cin >> n >> a >> b;
    ll an = C.po(2,n);
    an-=1;
    if(an <0)
        an+=mod;
    an%=mod;
    an -= get(n,a);
    if(an <0)
        an+=mod;
    an%=mod;
    an -= get(n,b);
    if(an <0)
        an+=mod;
    an%=mod;
    g(an);


}
int main()
{

    FASTIO
    cin.tie(NULL);
    fflush(stdout);
    ll t = 1;
   // cin >> t;
    for(ll tcase = 1;tcase <= t;tcase++){
        solve();
        
    }
return 0;
}