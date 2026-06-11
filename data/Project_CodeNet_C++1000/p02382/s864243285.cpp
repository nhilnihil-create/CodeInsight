#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int n;
    double vol_1 = 0.0, vol_2 = 0.0, vol_3 =0.0, vol_m=0.0, x[1000], y[1000], avg = 0.0;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    for (int i = 0; i < n; i++){
        cin >> y[i];
    }
    for (int i = 0; i < n; i++){
        vol_1 += abs(x[i]-y[i]);
    }
    for (int i = 0; i < n; i++){
        vol_2 += pow(abs(x[i]-y[i]), 2.0);
    }
    vol_2 = sqrt(vol_2);
    for (int i = 0; i < n; i++){
        vol_3 += pow(abs(x[i]-y[i]), 3.0);
    }
    vol_3 = pow(vol_3, 1.0/3.0);
    for(int i = 0; i < n; i++){
        vol_m = max(abs(x[i]-y[i]),vol_m);
    }  
    printf("%lf\n%lf\n%lf\n%lf\n", vol_1, vol_2, vol_3, vol_m);

    return 0;
}
