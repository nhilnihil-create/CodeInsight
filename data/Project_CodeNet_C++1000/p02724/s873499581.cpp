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
        long x;
        cin >> x;

        long ans = 0;
        long k = x / 500;
        ans += 1000 * k;
        x -= 500 * k;
        k = x / 5;
        ans += 5 * k;
        printf("%lld\n", ans);
    }
}
