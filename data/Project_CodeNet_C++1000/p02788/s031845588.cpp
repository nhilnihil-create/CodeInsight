#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll,ll>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 2*1e5;
const int mod = 1e9+7;

template<class T>
struct BIT {
    vector<T> bit;
    int n;
    BIT(int n): n(n), bit(n+1){}

    void add(int i, T x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

int main() {
    int n;
    ll d, a; 
    cin >> n >> d >> a;
    vector<P> data(n);
    rep(i,n) {
        ll x, h; cin >> x >> h;
        data[i] = P(x,h);
    }
    sort(all(data));
    vll x(n), h(n);
    rep(i,n) {
        x[i] = data[i].first;
        h[i] = data[i].second;
    }
    BIT<ll> bit(n+1);
    ll ct = 0;
    REP(i,n+1) {
        h[i-1] -= bit.sum(i);
        if (h[i-1] <= 0) continue;
        ll n_attack = (h[i-1]+a-1)/a;
        ll damage = n_attack * a;
        ct += n_attack;
        bit.add(i,damage);
        int rx = upper_bound(all(x),x[i-1]+2*d)-x.begin();
        if (rx != n) bit.add(rx+1,-damage);
    }
    cout << ct << endl;
}