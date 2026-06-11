#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

ll g(ll k) {
    ll x = k * (k + 1) / 2;
    return x;
}

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    repl(i, 1, n + 1) {
        ans += i * g(n / i);
    }
    cout << ans << endl;
    return 0;
}
