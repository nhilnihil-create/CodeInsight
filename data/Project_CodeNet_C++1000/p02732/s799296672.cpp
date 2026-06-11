#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (998244353)
#define umap unordered_map

int main()
{
    long t = 1;
    //cin >> t;

    while (t--) {
        long n;
        cin >> n;

        vector<long> a(n);
        umap<long, long> d;
        for (auto &x : a) {
            cin >> x;
            d[x]++;
        }
        long total = 0;
        for (auto &p : d) {
            long k = p.second;
            total += k * (k-1) / 2;
        }
        for (auto &x : a) {
            long aux = total - (d[x] * (d[x] - 1)) / 2;
            aux += (d[x] - 1) * (d[x] - 2) / 2;
            long ans = aux;
            printf("%lld\n", ans);
        }
    }
}
