#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int l = 1, r = *max_element(ar, ar + n), m, ans = -1;
    while (l <= r) {
        m = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (ar[i] + m - 1) / m - 1;
        }
        if (cnt <= k) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (ans == -1) ans = 0;
    cout << ans << '\n';
    return 0;
}