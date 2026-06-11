#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 998244353;
string s;
signed main() {
    INCANT;
    int n, a[111111];
    int cnt[111111] = {};
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int ans = 1;
    if (a[0] != 0 || cnt[0] != 1) ans = 0;
    for (int i = 1; i < n; i++) {
        ans *= cnt[a[i] - 1];
        ans %= MOD;
    }
    cout<<ans<<endl;
}
