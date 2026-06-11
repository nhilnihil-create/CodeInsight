#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
int n;
vector<T> d;
BIT(int n=0):n(n),d(n+1) {}
void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
    d[i] += x;
    }
}
T sum(int i) { //[0,i]のsum
    T x = 0;
    for (i++; i; i -= i&-i) {
    x += d[i];
    }
    return x;
}
T sum(int l, int r) { // [l,r)のsum
    return sum(r-1) - sum(l-1);
}
};

int main()
{
    int n,d,a;
    cin >> n >> d >>a;
    vector<pll> p(n);
    rep(i,n)cin >> p[i].first >> p[i].second;
    BIT<ll> bit(n+5);
    sort(p.begin(),p.end());
    ll ans = 0;
    rep(i,n){
        ll x = p[i].first;
        ll h = p[i].second;
        int tot = bit.sum(i);
        h -= tot;
        if(h> 0){
            int num = (h+a-1)/a;
            ans += num;
            ll damage = num*a;
            bit.add(i,damage);
            ll hashi = min(x + 2*d+1,1001001001ll);
            int  ni = upper_bound(p.begin(),p.end(),pll(hashi,999))-p.begin();
            bit.add(ni,-damage);
        }

    }
    cout << ans << endl;
    return 0;
}