#include <bits/stdc++.h>

using namespace std;

#define long long long
#define INF 2e18
#define MOD (long) (998244353)
#define umap unordered_map

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long t = 1;
    //cin >> t;

    while (t--) {
        long a, b, c, d;
        cin >> a >> b >> c >> d;

        for (long i = 0; i < 1000; i++) {
            if (i % 2 == 0) {
                c -= b;
                if (c <= 0) {
                    puts("Yes");
                    return 0;
                }
            } else {
                a -= d;
                if (a <= 0) {
                    puts("No");
                    return 0;
                }
            }
        }
    }
}
