#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        size_t n;
        scanf("%zu", &n);
        if (!n) return 0;

        double sum=0, sq_sum=0;
        for (size_t i=0; i<n; ++i) {
            double s;
            scanf("%lf", &s);

            sum += s;
            sq_sum += s*s;
        }

        double stdev=sqrt((sq_sum-sum*sum/n)/n);
        printf("%.12f\n", stdev);
    }
}