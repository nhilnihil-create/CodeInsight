#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

////////////////////////////////////////////////////////

bool b[10000];

Vl frontzero(Vl v){
    reverse(ALL(v));
    v.push_back(0);
    reverse(ALL(v));
    return v;
}

int main() {
    ll n, k; cin >> n >> k;
    Vl p(n+1), c(n+1);
    Rep(i, 1, n) cin >> p[i];
    Rep(i, 1, n) cin >> c[i];

    ll ans = -INF;

    //サイクルに分解
    Rep(i, 1, n){
        if(b[i]) continue;
        ll start = i, now = i;
        Vl v;
        ll cs = 0; // 一周の和
        do{
            b[now] = true;
            v.push_back(c[now]);
            now = p[now];
            cs += c[now];
        }while(now != start);

        if(cs <= 0 || (cs > 0 && k <= sz(v)-1)){
            ll m = min(sz(v)-1, k);
            ll l = sz(v);
            Rep(j, 0, l) v.push_back(v[j]);
            v = frontzero(v);
            rep(j, 1, sz(v)) v[j] += v[j-1];
            rep(j, 0, sz(v)-m){
                Rep(kk, j+1, j+m){
                    ll su = v[kk]-v[j];
                    chmax(ans, su);
                }
            }
        }
        else { // cs >= 0 && k >= sz(v)
            ll m = sz(v);
            Rep(j, 0, m) v.push_back(v[j]);
            v = frontzero(v);
            rep(j, 1, sz(v)) v[j] += v[j-1];
            rep(j, 0, m){
                Rep(kk, j+1, j+m){
                    ll su = v[kk]-v[j];
                    su += cs*((k-(kk-j))/m);
                    chmax(ans, su);
                }
            }
        }
    }

    co(ans);

    return 0;
}
 
 
