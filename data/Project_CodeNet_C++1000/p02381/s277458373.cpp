#include <stdio.h>
#include <math.h>

int main()
{
    while (1){
        int n;

        scanf(" %d", &n);
        if (n == 0){
            break;
        }

        int score[n];

        for (int i = 0; i < n; i++){
            scanf(" %d", &score[i]);
        }

        int sum = 0;
        double ave;
       
        for (int i = 0; i < n; i++){
            sum += score[i];
        }
        
        ave = (double)sum / n;

        double alpha = 0;

        for (int i = 0; i < n; i++){
            alpha += pow(score[i] - ave, 2);
        }

        printf("%lf\n", sqrt(alpha/n));
    }

    return 0;
}
    