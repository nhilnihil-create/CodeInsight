#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
using namespace std; 
int main() {
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int y[n];
    for(int i = 0; i < n; i++){
        cin >> y[i];
    }
    
    int absf[n];
    for(int i = 0; i < n; i++){
        absf[i] = abs(x[i] - y[i]);
    }
    double d_1=0, d_2=0, d_3=0, d_inf=absf[0]; 
     
    for(int i = 0; i < n; i++){
        d_1 += absf[i];
    }
    cout << d_1 << endl;
     
    for(int i = 0; i < n; i++){
        d_2 += pow(absf[i], 2);
    }
    printf("%.6lf\n", sqrt(d_2));
     
    for(int i = 0; i < n; i++){
        d_3 += pow(absf[i], 3);
    }
    printf("%.6lf\n", cbrt(d_3));
     
    for(int i = 1; i < n; i++){
        if(d_inf < absf[i]){
            d_inf = absf[i];
        }
    }
    cout << d_inf << endl;
    
    return 0;
}
