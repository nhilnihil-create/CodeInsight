#include <iostream>
#include <math.h>

using namespace std;
int main(void){
    int n;
    cin >> n;
    
    int x[n],y[n];
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> y[i];
    
    double D_p1 = 0;
    for(int i=0;i<n;i++){
        D_p1 += fabs(x[i]-y[i]);
    } 
    
    double D_p2 = 0;
    for(int i=0;i<n;i++){
        D_p2 += pow(x[i]-y[i],2);
    } 
    D_p2 = sqrt(D_p2);

    double D_p3 = 0;
    for(int i=0;i<n;i++){
        D_p3 += pow(fabs(x[i]-y[i]),3);
    } 
    D_p3 = pow(D_p3,1.0/3.0);
    
    double D_p_inf = 0;
    for(int i=0;i<n;i++){
        if(fabs(x[i]-y[i])>D_p_inf) D_p_inf = fabs(x[i]-y[i]);
    } 

    cout << fixed << D_p1 << endl;
    cout << fixed << D_p2 << endl;
    cout << fixed << D_p3 << endl;
    cout << fixed << D_p_inf << endl;
    
}

