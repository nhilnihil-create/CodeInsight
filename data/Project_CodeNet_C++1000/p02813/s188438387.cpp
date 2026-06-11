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

        vector<long> p(n), q(n), init;
        for (auto &x : p) cin >> x;
        for (auto &x : q) cin >> x;

        init = p;
        sort(init.begin(), init.end());
        long a, b, x = 0, y = 0;
        do {
            x++;
            y++;
            if (init == p) a = x;
            if (init == q) b = y;
        } while (next_permutation(init.begin(), init.end()));

        long ans = abs(a - b);
        printf("%lld\n", ans);
    }
}
