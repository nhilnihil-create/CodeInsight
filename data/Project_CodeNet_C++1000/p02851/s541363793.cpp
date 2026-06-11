#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

LL a[200005];
LL prefix[200005];

unordered_map<LL, LL> m;
LL n, k;

LL mod(LL x) {
    return ((x % k) + k) % k;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    LL ans = 0;
    m[0] = 1;
    for (int i = 1; i <= n; i++) {
        ans += m[mod(prefix[i] - i)];
        if (i >= k - 1) {
            m[mod(prefix[i - k + 1] - (i - k + 1))]--;
        }
        // printf("ans = %lld\n", ans);
        m[mod(prefix[i] - i)]++;
    }
    cout << ans << endl;
}
