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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};

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

struct UnionFind {
    vector<ll> par;
    vector<ll> rank;
    vector<ll> Size;
    UnionFind(ll n) {
        init(n);
    }
 
    void init(ll n) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        rep0(i, n + 1){
            par[i] = i;
            rank[i] = 0;
            Size[i] = 1;
        }
    }
 
    ll root(ll x) {
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }
 
    bool same(ll x, ll y) {
        return root(x) == root(y);
    }
 
    bool merge(ll x, ll y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }
 
    ll size(ll x){
        return Size[root(x)];
    }
};

//modの値の確認をすること
int main(){
    ll n,ans = INF;
    cin >> n;
    if(n == 1){
        pf(1);
        return 0;
    }
    vector<pair<ll, ll>> pos(n);
    rep0(i, n){
        ll x,y;
        cin >> x >> y;
        pos[i] = make_pair(x, y);
    }
    sort(all(pos));
    rep0(i, n - 1)nfor(j, i + 1, n){
        pair<ll, ll> p = make_pair(pos[j].first - pos[i].first, pos[j].second - pos[i].second);
        UnionFind u(n);
        rep0(k, n - 1)nfor(m, k + 1, n)if(p.first == pos[m].first - pos[k].first && p.second == pos[m].second - pos[k].second)u.merge(m,k);
        vector<bool> used(n,false);
        ll cnt = 0;
        rep0(k, n){
            if(!used[u.root(k)]){
                used[u.root(k)] = true;
                cnt += 1;
            }
        }
        chmin(ans, cnt);
    }
    pf(ans);
    return 0;
}
