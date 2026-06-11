#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(void){
    cout<<fixed<<setprecision(6);
    
    int n;
    double x[1001]={}, y[1001]={};
    double d1=0.0, d2=0.0, d3=0.0, di=0.0;
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>x[i];
    for(int i=0; i<n; i++) cin>>y[i];
    
    for(int i=0; i<n; i++){
        d1+=fabs(x[i]-y[i]);
        d2+=fabs(x[i]-y[i])*fabs(x[i]-y[i]);
        d3+=fabs(x[i]-y[i])*fabs(x[i]-y[i])*fabs(x[i]-y[i]);
        di=max(di, fabs(x[i]-y[i]));
    }
    
    cout<<d1<<endl;
    cout<<sqrt(d2)<<endl;
    cout<<pow(d3, 1.0/3.0)<<endl;
    cout<<di<<endl;;
    
    return 0;
}

