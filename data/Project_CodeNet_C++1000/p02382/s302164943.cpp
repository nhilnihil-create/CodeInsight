#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(void){
    int n, i, x[100]={}, y[100]={};
    long double  D1=0, D2=0, D3=0,D4=0, proD4;
    cin >> n;
    
    for(i=0; i<n; i++){
        cin >> x[i];
    }
    for(i=0; i<n; i++){
        cin >> y[i];
    }
    
    for(i=0; i<n; i++){
        D1 += abs(x[i] - y[i]);
        D2 += pow((x[i] - y[i]), 2);
        D3 += pow(fabs(x[i] - y[i]), 3); 
        proD4 = abs(x[i] - y[i]);
        if(D4 < proD4) D4 = proD4;
    }
    
    D2 = sqrt(D2);
    D3 = pow(D3, pow(3, -1));
    
    cout << fixed << setprecision(8) << D1 << endl << D2 << endl << D3 << endl << D4 << endl;
    return 0;
    
}

