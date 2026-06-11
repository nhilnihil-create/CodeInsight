#include <cstdio>
#include <cmath>

int main()
{
    int n;
    double m, sum, sum_a;

    while (1) {
        sum = 0;
        sum_a = 0;
        scanf("%d", &n);
        if(n == 0) break;

        else {
            double score[n];
            for(int i = 0; i < n; i++){
                scanf("%lf", &score[i]);
                sum += score[i];
            }
            m = sum/n;
            for(int i = 0; i < n; i++){
                sum_a += (score[i] - m) * (score[i] - m);
            }
            printf("%lf\n", sqrt(sum_a/n));
        }
    }
    return 0;
}