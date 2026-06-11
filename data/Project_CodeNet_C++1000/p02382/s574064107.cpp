#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int n;
    double s;
    int x[1001];
    int y[1001];
    double z[1001];
    scanf(" %d", &n); 
    for(int i=0; i<n; ++i)
        scanf(" %d", &x[i]); 
    for(int i=0; i<n; ++i)
        scanf(" %d", &y[i]);
    for(int j = 0;j < n; j++) {
        z[j] = fabs(x[j]-y[j]);
    }
   
    for(int p = 1; p <= 3; p++) {
        s = 0;
        for(int k = 0; k < n; k++) {
            s += pow(fabs(x[k] - y[k]), p);
        }
        printf("%lf\n",pow(s,1.0/p));     
    } 
    double max = z[0];

    for(int t = 1; t < n; t++){
        if(max < z[t]){
            max = z[t];
        }
    }
    printf("%lf\n",max);
    return 0;
}
