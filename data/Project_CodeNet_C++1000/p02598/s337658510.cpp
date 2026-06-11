#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int A[202020];
int n, k;

bool check(double l) {
    int rest = k;
    rep(i, n) {
        rest -= ceil(A[i]/l) - 1;
    }
    if(rest >= 0) return true;
    else return false;
}

void solve() {
    cin >> n >> k;
    rep(i, n) cin >> A[i];
    long double ng = 0, ok = 1e9, eps = 1e-9;
    while(ok - ng > eps) {
        long double mid = (ok + ng) / 2;
        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ll fans = floor(ok), ans = ceil(ok);
    if (check(fans)) {
        cout << fans << endl;
    } else {
        cout << ans << endl;
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}