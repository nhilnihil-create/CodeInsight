#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double mdistance(vector<int> x, vector<int> y, size_t p) {
    /* Minkowski distance */
    double d=0;
    size_t n=x.size();

    if (p == 1) {
        // Manhattan distance
        for (size_t i=0; i<n; ++i)
            d += abs(x[i]-y[i]);

        return d;
    } else if (p == 2) {
        // Euclidean distance
        for (size_t i=0; i<n; ++i)
            d += (x[i]-y[i])*(x[i]-y[i]);

        return sqrt(d);
    } else if (p == 3) {
        for (size_t i=0; i<n; ++i) {
            int z=abs(x[i]-y[i]);
            d += z*z*z;
        }
        return cbrt(d);
    } else if (!~p) {
        // Chebyshev distance
        for (size_t i=0; i<n; ++i)
            d = max(d, 1.0*abs(x[i]-y[i]));

        return d;
    }

    return 0;
}

int main() {
    size_t n;
    scanf("%zu", &n);

    vector<int> x(n), y(n);

    for (size_t i=0; i<n; ++i)
        scanf("%d", &x[i]);

    for (size_t i=0; i<n; ++i)
        scanf("%d", &y[i]);

    for (size_t i=1; i<=3; ++i)
        printf("%.12f\n", mdistance(x, y, i));

    printf("%.12f\n", mdistance(x, y, -1));
    return 0;
}