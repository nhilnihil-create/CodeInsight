#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int i, n;
double sum, avg;
double s[1000];

int main(void){
    while (1){
        scanf("%d", &n);
        if (n == 0) break;
        for (i = 0; i < n; i++){
            scanf("%lf", &s[i]);
            sum += s[i];
        }
        avg = sum / n;
        sum = 0;
        for (i = 0; i < n; i++){
            sum += (s[i] - avg)*(s[i] - avg);
        }
        double sd = sqrt(sum/n);
        printf("%f\n", sd);
        sum = 0;
    }
    return 0;
}