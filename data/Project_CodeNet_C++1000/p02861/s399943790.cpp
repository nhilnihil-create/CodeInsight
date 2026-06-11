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

        vector<pair<long, long>> a(n);
        for (auto &p : a) {
            cin >> p.first >> p.second;
        }
        double sum = 0;
        for (long i = 0; i < n; i++) {
            for (long j = i+1; j < n; j++) {
                long xi = a[i].first;
                long yi = a[i].second;
                long xj = a[j].first;
                long yj = a[j].second;
                sum += sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
            }
        }
        double ans = 2 * sum / n;
        printf("%.10f\n", ans);
    }
}
