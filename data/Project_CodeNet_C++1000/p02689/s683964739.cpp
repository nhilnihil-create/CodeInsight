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
        long n, m;
        cin >> n >> m;

        vector<long> a(n);
        for (auto &x : a) cin >> x;

        set<long> s;
        while (m--) {
            long u, v;
            cin >> u >> v;

            if (a[u-1] <= a[v-1]) s.insert(u);
            if (a[v-1] <= a[u-1]) s.insert(v);
        }
        long ans = n - s.size();
        printf("%lld\n", ans);
    }
}
