#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
// #define DEBUG 10
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const ll mod = 1e9 + 7, maxn = 500050;
const double PI = acos(-1);
 
vector<int> p(maxn, 0);
void init(int n){
    for (int i=0; i<=n; i++){
        p[i] = i;
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<ll> r(a), g(b), u(c);
    priority_queue<ll> res;

    for (auto &x: r) cin >> x;
    for (auto &x: g) cin >> x;
    for (auto &x: u) cin >> x;
    sort(all(r));
    sort(all(g));
    sort(all(u));

    while (x--){
        res.push( - r.back());
        r.pop_back();
    }

    while (y--){
        res.push( -g.back());
        g.pop_back();
    }

    
    while (!u.empty()){
        x = u.back();
        u.pop_back();
        y = -res.top();
        res.pop();
        res.push(-max(x, y));
    }

    ll ans = 0;

    while (!res.empty()){
        ans += -res.top();
        res.pop();
    }

    cout << ans << endl;
    return 0;
}