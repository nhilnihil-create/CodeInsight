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

        long best = INF;
        for (long k = 1; k <= sqrt(n); k++) {
            if (n % k == 0) {
                long l = n/k;
                long aux = k + l - 2;
                best = min(aux, best);
            }
        }
        printf("%lld\n", best);
        return 0;
    }
}
