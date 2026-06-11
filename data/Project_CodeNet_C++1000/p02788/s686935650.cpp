#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
struct BIT{
    int n;
    vector<T> d;
    BIT(int n = 0):n(n), d(n+1){}
    void add(int i, T x = 1){
        for(i++; i <= n; i += i&-i){
            d[i] += x;
        }
    }
    T sum(int i){
        T x = 0;
        for(i++; i; i -= i&-i){
            x += d[i];
        }
        return x;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll d, a;
    cin >> n >> d >> a;
    vector<P> p;
    rep(i,n){
        ll x, h;
        cin >> x >> h;
        p.emplace_back(x, h);
    }
    sort(p.begin(), p.end());
    BIT<ll> bit(n+1);
    ll ans = 0;
    rep(i,n){
        ll x = p[i].first;
        ll h = p[i].second;
        h -= bit.sum(i);
        if(h <= 0) continue;
        ll num = (h + a - 1) / a;
        ans += num;
        ll damage = num * a;
        bit.add(i, damage);
        int rx = min(x+d*2, 1000000007LL);
        int range = upper_bound(p.begin(), p.end(), P(rx+1, -1)) - p.begin();
        bit.add(range, -damage);   
    }
    cout << ans << endl;
	return 0;
}