#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
const ll M = 1000000007;
 
vector<ll> fac(3000000); //n!(mod M)
vector<ll> ifac(3000000); //k!^{M-2} (mod M)
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
    if(a < b || a < 0 || b < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % M;
    return tmp * fac[a] % M;
}

ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}


ll dfs(bool b, ll k, ll a, ll p, const vvll &e){
    if(sz(e[a]) == 1&&b == false){
        return 1;
    }
    ll t = 1, s = sz(e[a]) - 1;
    if(b){s++;}
    ll n = k-2;
    if(b){n++;}
    t *= comb(n, s)*fac[s];
    t %= M;
    for(auto x: e[a]){
        if(x == p){
            continue;
        }
        t *= dfs(false, k, x, a, e);
        t %= M;
    }
    return  t;
}


int main(){
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i<3000000; i++){
        fac[i+1] = fac[i]*(i+1) % M; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
    ll N, K; cin >> N >> K;
    vvll e(N, vll(0));
    rep(i, 0, N-1){
        ll a, b; cin >> a >> b;
        e[a-1].emplace_back(b-1);
        e[b-1].emplace_back(a-1);
    }
    ll ans = K*dfs(true, K, 0, INF, e)%M;
    prt(ans);
}







