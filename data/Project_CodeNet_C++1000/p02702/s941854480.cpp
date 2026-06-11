#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    const int MOD = 2019;
    const int n = S.size();
    int cnt[2019] = {0};

    int64_t r[n+1] = {0};
    int64_t p = 1;
    cnt[0] = 1; 
    for (int i = n - 1; i >= 0; --i) {
        r[i] = r[i + 1] + p * (S[i] - '0');
        r[i] %= MOD;
        p = p * 10 % MOD;
        ++cnt[r[i]];
    }

    int64_t ans = 0;
    for (int i = 0; i < 2019; ++i) {
        // printf("cnt[%d]=%d\n", i, cnt[i]);
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }
    
    std::cout << ans << std::endl;

    return 0;
}
