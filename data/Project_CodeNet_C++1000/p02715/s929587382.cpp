#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int bin_pow(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        int curr = bin_pow(x, y / 2);
        return (curr * curr) % mod;
    }
    else {
        return (bin_pow(x, y - 1) * x) % mod;
    }
}

int cnt[200005];
int32_t main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = k; i >= 1; i--) {
        int curr_ans = bin_pow(k / i, n);
        cnt[i] = curr_ans;
        for (int j = i + i; j <= k; j += i) {
            cnt[i] = (cnt[i] - cnt[j] + mod) % mod;
        }
        ans += (i * cnt[i]) % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}
