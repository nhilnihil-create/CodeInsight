#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+9;
int n;
ll ans;

int main() {
    cin >> n;
    
    for(int i=1; i<=n; ++i) ans = ans + 1LL * i * (i + 1) / 2;
    
    for(int i=1; i<=n-1; ++i) {
        int x, y; cin >> x >> y;
        ans -= 1LL * min(x, y) * (n-max(x, y) + 1);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
