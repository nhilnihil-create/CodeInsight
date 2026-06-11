#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define debug(x) cerr <<__LINE__<< ": " <<#x<< " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

ll gcd(ll a, ll b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> A(n);
    rep(i, n) cin >> A[i], A[i] >>= 1;
    ll x = 1;
    rep(i, n) {
        x = lcm(x, A[i]);
        if (x > m) {
            cout << 0 << endl;
            return;
        }
    }
    rep(i, n) {
        if (x / A[i] % 2 == 0) {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 0;
    if (m >= x) ans++, m -= x;
    ans += m / (2 * x);
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
