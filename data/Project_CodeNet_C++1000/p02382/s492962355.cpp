#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int n,i;
    long long D1=0.0f,D2=0.0f,D3=0.0f,D=0.0f,d;
    cin >> n;
    int x[n],y[n];
    for (i=0;i<n;i++) cin >> x[i];
    for (i=0;i<n;i++) cin >> y[i];
    for (i=0;i<n;i++) {
        d = abs(x[i]-y[i]);
        D1 += d;
        D2 += d*d;
        D3 += d*d*d;
        if (D < d) D = d;
    }
    printf("%.8f\n%.8f\n%.8f\n%.8f\n", (double)D1, sqrt((double)D2), pow((double)D3,1.0/3.0), (double)D);
    return 0;
}