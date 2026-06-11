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
        long n;
        cin >> n;

        vector<long> a(n);
        umap<long, long> di, dj;
        for (long i = 0; i < n; i++) {
            cin >> a[i];
            di[a[i] + i + 1]++;
            dj[i + 1 - a[i]]++;
        }
        long ans = 0;
        for (auto &p : di) {
            long count = p.second * dj[p.first];
            ans += count;
        }
        printf("%lld\n", ans);
    }
}
