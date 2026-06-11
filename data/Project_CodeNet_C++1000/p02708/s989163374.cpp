#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 1e9 + 7;
int n, k;

int sum(int n) {
    return n * (n + 1) / 2;
}

int ssum(int start, int end) {
    int ret = 0;
    return sum(end) - sum(start - 1);
}

signed main() {
    cin>>n>>k;
    int ans = 0;
    for (int i = k; i <= n + 1; i++) {
        ans += ssum(n - i + 1, n) - ssum(0, i - 1) + 1;
        ans %= MOD;
    }
    cout<<ans<<endl;
}