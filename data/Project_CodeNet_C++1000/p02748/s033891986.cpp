#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const ll INF = 100100100;

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    vector<ll> A(a);
    vector<ll> B(b);
    rep(i, a) cin >> A[i];
    rep(i, b) cin >> B[i];
    ll mini = INF;
    rep(i, m) {
        ll x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        mini = min(mini, A[x] + B[y] - c);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    cout << min(mini, A[0] + B[0]) << endl;
    return 0;
}