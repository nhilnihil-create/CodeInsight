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
        long n;
        cin >> n;

        double ans = pow(double(n) / 3, 3);
        printf("%.10f\n", ans);
    }
}
