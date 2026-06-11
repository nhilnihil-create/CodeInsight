#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int i, n, x[100], y[100];
int distance(int k);int distance_infinit(void);

int main(void){
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    for (i = 0; i < n; i++){
        scanf("%d", &y[i]);
    }
    distance(1);
    distance(2);
    distance(3);
    distance_infinit();
    return 0;
}

int distance(int k){
    double sum = 0;
    for (i = 0; i < n; i++){
        sum += pow(fabs(x[i] - y[i]), k);
    }
    printf("%f\n", pow(sum, 1.0/k));
    return 0;
}

int distance_infinit(void){
    int max = 0;
    for (i = 0; i < n; i++){
        if (fabs(x[i] - y[i]) > max) max = fabs(x[i] - y[i]);
    }
    printf("%d\n", max);
    return 0;
}