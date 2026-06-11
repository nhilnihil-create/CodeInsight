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
    return ans % mod;
}

//modの値の確認をすること
int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> e(n);
    vector<vector<ll> > g(n,vector<ll>(0));
    vector<ll> color(n,-1);
    color[0] = -2;
    rep0(i, n - 1){
        ll a,b;
        cin >> a >> b;
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
        e[i].first = a;
        e[i].second = b;
    }
    ll k = 0;
    rep0(i, n)chmax(k, ll(g[i].size()));
    
    queue<ll> to,from,erase;
    to.push(0);
    map<pair<ll, ll>,ll> m;
    while (!to.empty()) {
        from = to;
        to = erase;
        while (!from.empty()) {
            ll f = from.front(),c = 0;
            rep0(i, g[f].size()){
                if(color[g[f][i]] != -1)continue;
                if(color[f] == c)++c;
                color[g[f][i]] = c;
                m[make_pair(f, g[f][i])] = c;
                ++c;
                to.push(g[f][i]);
            }
            from.pop();
        }
    }
    pf(k);
    rep0(i, n - 1)pf(m[e[i]] + 1);
    return 0;
}
