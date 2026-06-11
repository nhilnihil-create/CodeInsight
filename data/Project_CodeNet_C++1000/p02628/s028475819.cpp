#include <bits/stdc++.h>
#define in(x) freopen(x, "r", stdin)
#define out(x) freopen(x, "w", stdout)
using namespace std;

int n, k;
int a[10000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
                
    #ifndef _LOCAL          
    #endif // _LOCAL

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < k; ++i)
        ans += a[i];
    cout << ans << "\n";

    return 0;
}