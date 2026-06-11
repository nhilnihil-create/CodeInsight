// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int x, int y) {
    while(x % y == 0)
        x /= y;
    return x % y == 1;
}

int count(int n) {
    int cnt = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cnt++;
            if(i * i != n)
                cnt++;
        }
    }
    return max(cnt, 1LL);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n;
        cin >> n;

        int ans = 0;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                ans += check(n, i);
                if(i * i != n)
                    ans += check(n, n / i);
            }
        }
        ans += count(n - 1);

        cout << ans << '\n';
    }
    
    return 0;
}

