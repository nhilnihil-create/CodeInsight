#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
#define ld long double
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////


int main() {
    ll n; cin >> n;
    Vl a(n);
    rep(i, 0, n) cin >> a[i];
    
    ll c[] = {0, 0, 0};
    ll ans = 1;
    rep(i, 0, n){
        ll cnt = 0; int id = -1;
        if(a[i] == c[0]){
            cnt++; id = 0;
        }
        if(a[i] == c[1]){
            cnt++; id = 1;
        }
        if(a[i] == c[2]){
            cnt++; id = 2;
        }
        if(id == -1){
            co(0);
            return 0;
        }
        ans *= cnt;
        ans %= MOD;
        c[id]++;
    }
    co(ans);

    return 0;
}
