#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (1e9 + 7)
#define umap unordered_map

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long n;
        cin >> n;

        vector<long> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        long k = 0;
        for (long i = 0; i < n; i++) {
            if (a[i] == k+1) k++;
        }
        if (k == 0) {
            puts("-1");
            return 0;
        }
        long l = 1;
        long ans = 0;
        for (long i = 0; i < n; i++) {
            if (a[i] != l) ans++;
            else l++;
        }
        printf("%lld\n", ans);
    }
}
