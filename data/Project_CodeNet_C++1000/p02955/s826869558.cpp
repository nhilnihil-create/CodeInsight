#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 505;

int n, k, sum, ans;
int a[maxn];
vector < int > d;

signed main () {
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            d.push_back(i);
            d.push_back(sum / i);
        }
    }
    for (int x: d) {
        vector < int > b;
        int add = 0, rm = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % x) {
                b.push_back(a[i] % x);
                add += x - b.back();
            }
        }
        sort(b.begin(), b.end());
        int cur = add;
        for (int i = 0; i < b.size(); ++i) {
            rm += b[i];
            add -= x - b[i];
            cur = min(cur, max(rm, add));
        }
        if (cur <= k)
            ans = max(x, ans);
    }
    printf("%lld\n", ans);
}
