#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define chmax(x,y) x = max(x, y)
#define chmin(x,y) x = min(x, y)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int k;
    cin >> k;
    queue<ll> q;
    repl(i, 1, 10) {
        q.push(i);
    }
    ll ans = 0;
    rep(i, k) {
        ll x = q.front();
        if(i == k - 1) ans = (ll) x;
        q.pop();
        if(x % 10) {
            ll u = 10 * x + (x % 10) - 1;
            q.push(u);
        }
        ll v = 10 * x + (x % 10);
        q.push(v);
        if(x % 10 != 9) {
            ll w = 10 * x + (x % 10) + 1;
            q.push(w);
        }
    }
    cout << ans << endl;
    return 0;
}
