#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const ll INF = 1001001001001001;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll S = 0;
    rep(i, n) S += a[i];
    ll mi = S;
    ll sum = 0;
    rep(i, n) {
        sum += a[i];
        mi = min(mi, abs(sum - (S - sum)));
    }
    cout << mi << endl;
    return 0;
}
