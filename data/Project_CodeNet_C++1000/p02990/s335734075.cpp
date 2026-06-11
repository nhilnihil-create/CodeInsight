#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
const ll M = MOD;

vector<ll> fac(2001); //n!(mod M)
vector<ll> ifac(2001); //k!^{M-2} (mod M)
//a,bの範囲的にこれだけ配列を用意していけば十分

ll mpow(ll x, ll n){ //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}

ll comb(ll a, ll b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

int main(){
    int N,K;
    cin >> N >> K;
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<2000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    rep(i,K){
        ll tmp = comb(N - K + 1,i+1);
        ll tmp2 = comb(K-1,i);
        cout << tmp*tmp2 % MOD << endl;
    }
}