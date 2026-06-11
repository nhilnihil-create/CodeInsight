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
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<29;
const ll LINF = 1LL<<58;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n % 2 == 1) {
        rep(i, m) {
            cout << i + 1 << " " << n - i << endl;
        }
    } else {
        int l = 1, r = n;
        rep(i, m) {
            if (r - l > n / 2) {
                cout << l << " " << r << endl;
            } else {
                cout << l << " " << r - 1 << endl;
            }
            l++; r--;
        }
    }
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
