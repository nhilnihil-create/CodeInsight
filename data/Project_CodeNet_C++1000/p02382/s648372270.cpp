#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double mdistance(vector<int> x, vector<int> y, double p) {
    /* Minkowski distance */
    double d=0;
    size_t n=x.size();

    if (p < INFINITY) {
        for (size_t i=0; i<n; ++i)
            d += pow(abs(x[i]-y[i]), p);

        d = pow(d, 1.0/p);
    } else {
        // Chebyshew distance
        for (size_t i=0; i<n; ++i)
            d = max(d, 1.0*abs(x[i]-y[i]));
    }

    return d;
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

    printf("%.12f\n", mdistance(x, y, INFINITY));
    return 0;
}