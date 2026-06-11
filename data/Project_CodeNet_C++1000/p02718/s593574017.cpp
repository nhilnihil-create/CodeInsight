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
        long m, n;
        cin >> n >> m;

        vector<long> a(n);
        long total = 0;
        for (auto &x : a) {
            cin >> x;
            total += x;
            x *= 4*m;
        }
        long count = 0;
        for (auto &x : a) {
            if (x >= total) count++;
        }
        if (count >= m) puts("Yes");
        else puts("No");
    }
}
