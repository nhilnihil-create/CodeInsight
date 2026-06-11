#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20);
#define int long long
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
template<class T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<class T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
#define _rev(i, n) revi(i, n, 0)
#define revi(i, a, b) for(int i = (int)(a - 1); i >= (int)(b); i--)
#define rev(...) _overload(__VA_ARGS__, revi, _rev)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
const int INF = 1e18, MOD = 1e9 + 7;
signed main() {
    INCANT;
    int n, p, l2, l1, r1, r2, res = 0;
    cin>>n;
    int index[111111];
    rep(i, n) {
        cin>>p;
        index[p] = i;
    }
    multiset<int> s;
    s.insert(-1);
    s.insert(-1);
    s.insert(n);
    s.insert(n);
    rev(i, n + 1, 1) {
        auto now = s.lower_bound(index[i]);
        r1 = *now;
        r2 = *++now;
        l1 = *----now;
        l2 = *--now;
        res += ((l1 - l2) * (r1 - index[i]) + (r2 - r1) * (index[i] - l1)) * i;
        s.insert(index[i]);
    }
    cout<<res<<endl;
}
