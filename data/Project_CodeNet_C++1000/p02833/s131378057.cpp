#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (1e9 + 7)
#define umap unordered_map

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long n;
        cin >> n;

        if (n % 2 == 1) {
            puts("0");
            return 0;
        }
        long ans = n / 10;
        for (long pot = 50; pot <= 1e18; pot *= 5) {
            ans += n / pot;
        }
        printf("%lld\n", ans);
    }
}
