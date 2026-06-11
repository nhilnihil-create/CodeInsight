#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = ll(1e12);
const ll mod = ll(1e9+7);
const double pi = acos(-1);
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()
#define yes pf("Yes")
#define no pf("No")

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll ans = 1;
    rep1(i, n){
        ans *= i;
        ans %= mod;
    }
    return ans;
}

ll power(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b) {
        if(b & 1LL) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

vector<ll> FactorialInv, Factorial;

void init_combination(ll MAX){
    Factorial.resize(MAX + 1);
    FactorialInv.resize(MAX + 1);
    Factorial[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = power(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
}

ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    if(b < 0) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

//modの値の確認をすること
int main(){
    ll h,w;
    cin >> h >> w;
    vector<vector<ll> > dp(h,vector<ll>(w,INF)),g(h + 1,vector<ll>(w + 1,0ll));
    dp[0][0] = 0;
    rep0(i, h)rep0(j, w){
        char c;
        cin >> c;
        if(c == '#')g[i][j] = 1;
    }
    rep0(i, h)rep0(j, w){
        if(i != h-1) dp[i + 1][j] = min(dp[i + 1][j],dp[i][j] + (g[i][j] == g[i + 1][j]? 0:1));
        if(j != w-1) dp[i][j + 1] = min(dp[i][j + 1],dp[i][j] + (g[i][j] == g[i][j + 1]? 0:1));
    }
    ll ans = dp[h - 1][w - 1] + g[0][0] + g[h - 1][w - 1];
    pf(ans / 2);
    return 0;
}
