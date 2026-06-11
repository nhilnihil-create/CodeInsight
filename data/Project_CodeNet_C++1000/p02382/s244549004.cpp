#include <cstdio>
#include <cmath>

int main()
{
    int n;
    scanf("%d", &n);

    double x[n], y[n];
    for(int i = 0; i < n; i++){
        scanf("%lf", &x[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &y[i]);
    }

    int p[3] = {1, 2, 3};
    double distance[n], sum, max;

    for(int i = 0; i < 3; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            sum += pow(fabs(y[j] - x[j]), p[i]);
        }
        printf("%lf\n", pow(sum, 1.0/p[i]));
    }

    for(int i = 0; i < n; i++){
        distance[i] = fabs(y[i] - x[i]);
    }

    max = distance[0];

    for(int i = 0; i < n; i++){
        if(max < distance[i]) max = distance[i];
    }

    printf("%lf\n", max);
    return 0;
}