#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF ((long) 2e18)
#define MOD ((long) (1e9 + 7))
#define umap unordered_map

int main()
{
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long n, k;
        cin >> n >> k;

        vector<long> a(n), f(n);
        for (auto &x : a) cin >> x;
        for (auto &x : f) cin >> x;

        sort(a.begin(), a.end());
        sort(f.begin(), f.end(), greater<long>());

        long l = 0;
        long r = INF;
        long best = INF;
        while (l < r) {
            long mid = (l + r) / 2;
            long aux = k;
            bool ok = true;
            for (long i = 0; i < n; i++) {
                long mult = a[i] * f[i];
                long diff = max(mult - mid, 0LL);
                long count = (diff + f[i] - 1) / f[i];
                aux -= count;
                if (aux < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                best = min(best, mid);
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%lld\n", best);
    }
}
