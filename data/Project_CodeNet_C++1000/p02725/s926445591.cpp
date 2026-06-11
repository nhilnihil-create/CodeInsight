#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF ((long) 2e18)
#define MOD ((long) (998244353))
#define umap unordered_map

struct Node
{
    long total = 1;
    set<long> adj;
};

int main()
{
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long k, n;
        cin >> k >> n;

        vector<long> a(n);
        for (auto &x : a) cin >> x;

        long best = INF;
        for (long i = 0; i < n-1; i++) {
            long dist = k - (a[i+1] - a[i]);
            best = min(best, dist);
        }
        long dist = a[n-1] - a[0];
        best = min(dist, best);
        printf("%lld\n", best);
    }
}
