#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int N = 2e5 + 5;

int n, k, maxim;
int a[N];

int up(int x, int y) {
    return x % y == 0 ? x / y : x / y + 1;
}

int binser(int l, int r) {
    int ret, mid, needed;
    while(l <= r) {
        mid = (l + r) / 2, needed = 0;
        for(int i = 1; i <= n; i++) {
            needed += up(a[i], mid) - 1;
        }
        if(needed <= k) {
            ret = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        maxim = max(maxim, a[i]);
    }
    cout << binser(1, maxim) << '\n';
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}