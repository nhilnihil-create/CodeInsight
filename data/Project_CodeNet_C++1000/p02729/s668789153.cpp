#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (998244353)

int main()
{
    long t = 1;
    //cin >> t;

    while (t--) {
        long n, m;
        cin >> n >> m;

        long ans = n*(n-1)/2 + m*(m-1)/2;
        printf("%lld\n", ans);
    }
}
