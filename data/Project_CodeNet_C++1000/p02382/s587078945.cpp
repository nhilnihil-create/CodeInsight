#include <cstdio>
#include <cmath>
 
double minkowski(int* x, int* y, int n, int p) {
    double d = 0.0;
    for (int i = 0; i < n; i++) d += pow(fabs((double)(x[i] - y[i])), p);
    return pow(d, 1.0 / p);
}
 
int minkowski_infinite(int* x, int* y, int n) {
    int max = -1;
    for (int i = 0; i < n; i++) if (max < fabs((double)(x[i] - y[i]))) max = fabs((double)(x[i] - y[i]));
    return max;
}
 
int main(void){
    int n;
    scanf("%d", &n);
 
    int x[100], y[100];
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    for (int i = 0; i < n; i++) scanf("%d", &y[i]);
 
    printf("%.5lf\n", minkowski(x, y, n, 1));
    printf("%.5lf\n", minkowski(x, y, n, 2));
    printf("%.5lf\n", minkowski(x, y, n, 3));
    printf("%.5lf\n", (double)minkowski_infinite(x, y, n));
 
    return 0;
}