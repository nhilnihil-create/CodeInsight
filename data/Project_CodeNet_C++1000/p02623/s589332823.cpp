#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v) cerr << #v << ":"; rep(i, v.size()) cerr << " " << v[i]; cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> A(n + 2, 0), B(m + 2, 0);
    rep(i, n){
        ll a;
        cin >> a;
        A[i + 1] = A[i] + a;
    }
    rep(i, m){
        ll b;
        cin >> b;
        B[i + 1] = B[i] + b;
    }
    A[n + 1] = LINF;
    B[m + 1] = LINF;
    int ans = 0;
    rep(i, n + 1) {
        if (A[i] > k) break;
        int books = i + upper_bound(all(B), k - A[i]) - B.begin() - 1;
        chmax(ans, books);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
