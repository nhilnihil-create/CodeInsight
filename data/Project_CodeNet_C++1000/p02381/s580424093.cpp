#include <cstdio>
#include <cmath>

int main(void){
    while (true) {
        int n, sum = 0, ss = 0;
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            int data;
            scanf("%d", &data);
            sum += data;
            ss += data * data;
        }
        double mean = (double)sum / n;
        double sd = sqrt((double)ss / n - mean * mean);
        printf("%lf\n", sd);
    }

    return 0;
}