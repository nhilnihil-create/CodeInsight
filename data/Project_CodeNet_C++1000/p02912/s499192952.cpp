#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<ll> q;
    rep(i,n) {
        ll a;
        cin >> a;
        q.push(a);
    }
    rep(i,m) {
        ll a = q.top(); q.pop();
        a /= 2;
        q.push(a);
    }
    ll ans = 0;
    while (!q.empty()) {
        ans += q.top(); q.pop();
    }
    cout << ans << endl;
    return 0;
}