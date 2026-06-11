#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll rui(ll a,ll b){
     ll ans=1;
     while(b>0){
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
     return ans % MOD;
}

ll COM(ll a, ll b){
    ll ans = 1;
    for(ll i=a; i>a-b; i--){
        ans = ans * i % MOD;
    }
    for(ll i=1; i<=b; i++){
        ans =(ans*rui(i, MOD-2)) % MOD;
    }
    return ans;
}

int main(){ 
    ll n, a, b; cin >> n >> a >> b;

    ll res = rui(2, n) - 1+ MOD*3 - COM(n,a) - COM(n,b);
    cout << res % MOD << ln;
}