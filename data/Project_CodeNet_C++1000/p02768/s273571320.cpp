#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e18;
const double PI=3.1415926535897932;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod


const ll MaxN=201001;

ll f[MaxN], rf[MaxN];
ll inv(ll x) {
    ll res = 1;
    ll k = mod - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % mod;
        y = (y * y) % mod;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    REP(i, 1, MaxN) f[i] = (f[i - 1] * i) % mod;
    REP(i, 0, MaxN) rf[i] = inv(f[i]);
}
//---------------------------------------------------------------------------------------------------
ll C(ll n, ll k) {
    ll a=1;
    REP(i,n-k+1,n+1) a=(a*i)%mod;
    ll c = rf[k]; // = k
    return (a * c) % mod;
}

ll ruijou(ll n, ll k){
    if(!k) return 1;
    ll a=ruijou(n,k/2);
    a=(a*a)%mod;
    return k%2 ? (a*n)%mod : a;
}


int main(){
    init();
    ll N,A,B; cin>>N>>A>>B;
    ll ans=ruijou(2,N);
    ans=(ans+mod-C(N,A))%mod;
    ans=(ans+mod-C(N,B))%mod;
    cout<<(ans-1+mod)%mod<<endl;
}