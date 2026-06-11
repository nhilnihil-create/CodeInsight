#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    int n, a;
    int sum[111111] = {};
    cin>>n;
    for (int i = 0; i <= n; i++) {
        cin>>a;
        if (i == 0 && a != 0 && !(a == 1 && n == 0)) {
            cout<<-1<<endl;
            return 0;
        }
        sum[i + 1] = sum[i] + a;
    }
    int ans = 0, cnt;
    for (int i = 0; i <= n + 1; i++) {
        if (i == 0) cnt = 1;
        else {
            a = sum[i] - sum[i - 1];
            if (cnt < a) {
                cout<<-1<<endl;
                return 0;
            }
            cnt -= a;
            cnt *= 2;
        }
        
        cnt = min(cnt, sum[n + 1] - sum[i]);
        ans += cnt;
    }
    cout<<ans<<endl;
}