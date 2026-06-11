#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    int n, ld, md;
    cin>>n;
    int cnt[11][11] = {};
    for (int i = 1; i <= n; i++) {
        ld = i % 10;
        md = i;
        while (md > 9) {
            md /= 10;
        }
        cnt[md][ld]++;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout<<ans<<endl;
}