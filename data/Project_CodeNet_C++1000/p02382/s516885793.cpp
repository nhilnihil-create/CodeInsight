#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    vector<int> x, y;
    double l1_norm, l2_norm, l3_norm, linf_norm;
    l1_norm = 0.0;
    l2_norm = 0.0;
    l3_norm = 0.0;
    linf_norm = 0.0;
    
    cin >> n;
    x.resize(n);
    y.resize(n);
    for (int i=0; i<n; ++i){
        cin >> x[i];
    }
    for (int i=0; i<n; ++i){
        cin >> y[i];
    }
    
    // l1_norm
    for (int i=0; i<n; ++i){
        l1_norm += abs(x[i] - y[i]);
    }
    
    // l2_norm
    for (int i=0; i<n; ++i){
        l2_norm += pow(x[i] - y[i], 2);
        if (i == n-1){
            l2_norm = sqrt(l2_norm);
        }
    }
    
    // l3_norm
    for (int i=0; i<n; ++i){
        l3_norm += pow(abs(x[i] - y[i]), 3);
        if (i == n-1){
            l3_norm = pow(l3_norm, 1.0 / 3.0);
        }
    }
    
    // l_infty_norm
    for (int i=0; i<n; ++i){
        if(abs(x[i] - y[i]) >= linf_norm){
            linf_norm = abs(x[i] - y[i]);
        }
    }
    
    printf("%.8f\n", l1_norm);
    printf("%.8f\n", l2_norm);
    printf("%.8f\n", l3_norm);
    printf("%.8f\n", linf_norm);
    return 0;
}

