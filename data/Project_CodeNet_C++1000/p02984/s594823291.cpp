#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    int n;
    cin>>n;
    int x = 0;
    int a[111111];
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        x += a[i];
        if (i % 2 == 0) x -= 2 * a[i];
    }
    for (int i = 1; i <= n; i++) {
        cout<<x<<' ';
        x = 2 * a[i] - x;
    }
    cout<<endl;
}