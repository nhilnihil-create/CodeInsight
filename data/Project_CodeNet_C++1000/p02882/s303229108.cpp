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
        double a, b, x;
        cin >> a >> b >> x;

        double y = (2*x - a*a*b) / (a*a);
        double alpha;
        if (y > 0) {
            double aux = b - y;
            alpha = 180 / acos(-1) * atan(aux / a);
        } else {
            y = (2 * x) / (a * b);
            alpha = 90.0 - (180 / acos(-1) * atan(y / b));
        }
        printf("%.10f\n", alpha);
    }
}
