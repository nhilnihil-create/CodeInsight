#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define ll long long int

ll mod=1e9+7;

const int nax=5005;

vector<ll> facs(nax);
vector<ll> inv(nax);

ll bin_exp(ll n,ll k){
    if(k==0)return 1;
    if(k==1)return n;
    ll c=1;
    if(k%2!=0){
        c=n;
        k-=1;
    }
    ll temp=bin_exp(n,k/2);
    temp=(temp*temp)%mod;
    temp=(temp*c)%mod;
    return temp;
}

ll egcd(ll a,ll b, ll &x, ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x_t,y_t;
    ll d=egcd(b,a%b,x_t,y_t);
    x=y_t;
    y=x_t-y_t*(a/b);
    return d;
}

void fill(){
    facs[1]=1;
    facs[0]=1;
    for(ll i=2;i<nax;i++){
        facs[i]=i*facs[i-1];
        facs[i]%=mod;
    }
    ll x,y;
    for(ll i=0;i<nax;i++){
        ll f=egcd(facs[i],mod,x,y);
        inv[i]=x;
    }
    return;
}

ll c_with_rep(int n,int r){
    if(n==0 || r==1)return 1;
    //if(n==1)return r;
    debug(n,r);
    //dis n objects among r returns n+r-1Cr-1
    ll ret=facs[n+r-1];
    debug(ret,facs[n+r-1]);
    ret=(ret*inv[n])%mod;
    ret=(ret+mod)%mod;
    debug(ret,inv[n]);
    ret=(ret*inv[r-1])%mod;
    ret=(ret+mod)%mod;
    debug(ret,inv[r-1]);
    return ret;
}

int main(){
    fill();
    int n,k;
    scanf("%d%d",&n,&k);
    int red=n-k;
    vector<ll> ans(k+1);
    for(int i=1;i<=red;i++){
        debug("Using these spaces:",i);
        ll red_ways=c_with_rep(red-i,i);
        if(i!=1){
            ans[i-1]=(ans[i-1]+red_ways*c_with_rep(k-i+1,i-1))%mod;
        }
        debug(ans);
        if(k<i)break;
        ll blue_ways=c_with_rep(k-i,i);
        ans[i]=(ans[i]+red_ways*blue_ways*2)%mod;
        if(k<i+1)continue;
        blue_ways=c_with_rep(k-i-1,i+1);
        ans[i+1]=(ans[i+1]+red_ways*blue_ways)%mod;
        debug(ans);
    }
    if(n==k)ans[1]=1;
    for(int i=1;i<=k;i++){
        cout<<(ans[i]+mod)%mod<<"\n";
    }
    return 0;
}
