#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long

int32_t main() {
    int n; 
    while(cin >> n) {
        int cnt[65];
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            for(int i = 0; i <= 60; i++){
                if( x & ( 1LL << i))cnt[i]++;
            }
        }
        int ans = 0;
        int p = 1;
        for(int i = 0; i <= 60; i++){
            ///cout << i << " " << cnt[i] << endl;
            int temp = (cnt[i]*(n-cnt[i])) % MOD;
            ///cout <<i << " " << temp*p << "\n";
            ans = (ans + (temp * p) % MOD) % MOD;
            p = (2 * p) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}