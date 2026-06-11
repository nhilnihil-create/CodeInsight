#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define debug(...) cerr<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)
    { for (auto v : vec) os << v << ' '; os << '\n'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
    { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
    { cerr << " " << H; debug_out(T...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    vector<ll> S(n + 1, 0);
    REP(i, 1, n) S[i] = S[i - 1] + A[i - 1];
    map<ll, int> mp;
    REP(i, 0, min(n, k - 1)) {
        mp[(S[i] - i) % k]++;
    }
    ll ans = 0;
    REP(i, 0, n) {
        mp[(S[i] - i) % k]--;
        ans += mp[(S[i] - i) % k];
        if (i + k > n) continue;
        mp[(S[i + k] - i - k) % k]++;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
