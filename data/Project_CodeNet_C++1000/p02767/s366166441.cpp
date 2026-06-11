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
        long total = 0;
        for (auto &x : a) {
            cin >> x;
            total += x;
        }
        long p = round(double(total) / n);
        long ans = 0;
        for (auto &x : a) {
            ans += (x - p) * (x - p);
        }
        printf("%lld\n", ans);
    }
}
