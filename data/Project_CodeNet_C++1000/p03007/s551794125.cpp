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
    int n, a, mn, mx;
    deque<int> q;
    vector<pair<int, int>> res;
    cin>>n;
    rep(i, n) {
        cin>>a;
        q.push_back(a);
    }
    sort(all(q));
    mx = q.back();
    mn = q.front();
    q.pop_back();
    q.pop_front();
    while(q.front() < 0 && !q.empty()) {
        res.push_back({mx, q.front()});
        mx -= q.front();
        q.pop_front();
    }
    while(!q.empty()) {
        res.push_back({mn, q.back()});
        mn -= q.back();
        q.pop_back();
    }
    cout<<mx - mn<<endl;
    each(p, res) {
        cout<<p.first<<' '<<p.second<<endl;
    }
    cout<<mx<<' '<<mn<<endl;
}
