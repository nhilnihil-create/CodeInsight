#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    ll h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    vvi l(h, vi(w,0)), r(h, vi(w,0)), u(h, vi(w,0)), d(h, vi(w,0));

    // 左方向
    for(ll i=0; i<h; i++){
        ll cur = 0;
        for(ll j=0; j<w; j++){
            (g[i].at(j) == '#') ? cur = 0 : cur++;
            l[i][j] = cur;
        }
    }
    // 右方向
    for(ll i=0; i<h; i++){
        ll cur = 0;
        for(ll j=w-1; j>=0; j--){
            (g[i].at(j) == '#') ? cur = 0 : cur++;
            r[i][j] = cur;
        }
    }
    // 下方向
    for(ll i=0; i<w; i++){
        ll cur = 0;
        for(ll j=h-1; j>=0; j--){
            (g[j].at(i) == '#') ? cur = 0 : cur++;
            d[j][i] = cur;
        }
    }
    // 上方向
    for(ll i=0; i<w; i++){
        ll cur = 0;
        for(ll j=0; j<h; j++){
            (g[j].at(i) == '#') ? cur = 0 : cur++;
            u[j][i] = cur;
        }
    }
    ll ans = 0;
    for(ll i=0; i<h; i++){
        for(ll j=0; j<w; j++){
            if(g[i].at(j) != '#') chmax(ans, l[i][j]+r[i][j]+d[i][j]+u[i][j]-3);
        }
    }
    cout << ans << endl;
}