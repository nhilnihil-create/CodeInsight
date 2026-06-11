#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

vint a, f;
int n;
ll k;

bool check(ll x) {
    vll mx(n);
    rep(i,n) mx[i] = x/f[i];
    ll ct = 0;
    rep(i,n) ct += max((ll)0,(ll)a[i]-mx[i]);
    return ct <= k;
}

int main() {
    cin >> n >> k;
    a.resize(n); 
    f.resize(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(rall(a));
    sort(all(f));
    ll l = -1;
    ll r = inf_l;
    while (r-l > 1) {
        ll mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}