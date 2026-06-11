#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
const ll MOD = 1e9+7;

#define pll pair<ll,ll>

const int MAX = 30000000;
ll f[MAX],finv[MAX],inv[MAX];
void COMinit(int N){
    f[0] = 1;
    f[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<=N;++i){
        f[i] = f[i-1]*i %MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) %MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int N, int K){
    if(N<K || N<0 || K <0){ return 0; }
    return f[N]*(finv[K]*finv[N-K]%MOD) %MOD;
}


int main(){
    ll N,K; cin>>N>>K;
    COMinit(N);
    for(int i=1;i<=K;++i){
        ll ans = COM(N-K+1,i) * COM(K-1,i-1);
        ans %= MOD;
        cout << ans << "\n";   
    }
}
