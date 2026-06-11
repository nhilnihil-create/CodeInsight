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
        long x;
        cin >> x;

        for (long a = -2e3; a < 2e3; a++) {
            for (long b = -2e3; b < 2e3; b++) {
                long a5 = a*a*a*a*a;
                long b5 = b*b*b*b*b;
                if (a5 - b5 == x) {
                    printf("%lld %lld\n", a, b);
                    return 0;
                }
            }
        }
    }
}
