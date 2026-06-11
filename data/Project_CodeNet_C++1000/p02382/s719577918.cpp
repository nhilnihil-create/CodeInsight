#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
 
int main(){
    int n;
    double x[1001], y[1001], sum[1001], d = 0.0;
 
    cin >> n;
    for (int i = 0; i < n; i++)  cin >> x[i];
    for (int i = 0; i < n; i++)  cin >> y[i];
 
    for (int i = 0; i < n; i++){
        sum[i] = fabs(x[i] - y[i]);
    }
 
    d = 0.0;
    for (int i = 0; i < n; i++){
        d += sum[i];
    }
    printf("%lf\n", d);
 
    d = 0.0;
    for (int i = 0; i < n; i++){
        d += pow(sum[i], 2);
    }
    printf("%lf\n", sqrt(d));
 
    d = 0.0;
    for (int i = 0; i < n; i++){
        d += pow(sum[i], 3);
    }
    printf("%lf\n", pow(d, 1.0/3));
 
    d = 0.0;
    for (int i = 0; i < n; i++){
        if (sum[i] > d)
            d = sum[i];
    }
    printf("%lf\n", d);
 
    return 0;
}