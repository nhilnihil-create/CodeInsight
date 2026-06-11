#include <bits/stdc++.h>
using namespace std;
int main() {
        int n, m, k, ans = 2e9;
        cin >> n >> m >> k;
        for(int i = 0; i <= m; ++i)
                for(int j = 0; j <= n; ++j)
                        if(i * n + j * m - i * j >= k) ans = min(ans, i + j);
        cout << ans;
        return 0;
}
