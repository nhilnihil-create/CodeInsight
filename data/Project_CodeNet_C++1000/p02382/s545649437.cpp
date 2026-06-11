#include <iostream>
using namespace std;
#include <cstdio>
#include <cmath>

int main() {
    int n, x[100], y[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    double p1 = 0, p2 = 0, p3 = 0, pInf[n];
    for (int i = 0; i < n; i++){
        p1 += fabs(x[i] - y[i]);
        p2 += pow(x[i] - y[i],2);
        p3 += pow(fabs(x[i] - y[i]),3);
        pInf[i] = fabs(x[i] - y[i]);
    }
    p2 = sqrt(p2);
    p3 = pow(p3,1.0/3);
    double pI = 0;
    for (int i = 0; i < n; i++){
        if (pI < pInf[i]) pI = pInf[i];
    }
    printf("%lf\n%lf\n%lf\n%lf\n",p1,p2,p3,pI);
    return 0;
}