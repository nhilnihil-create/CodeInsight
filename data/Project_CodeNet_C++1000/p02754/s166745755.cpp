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
        long n, a, b;
        cin >> n >> a >> b;

        long ans = n / (a + b);
        long aux = ans * (a + b);
        long r = n - aux;
        ans *= a;
        ans += min(a, r);
        printf("%lld\n", ans);
    }
}
