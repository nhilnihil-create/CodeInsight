#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int x[n];
    int y[n];

    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=0; i<n; i++){
        cin >> y[i];
    }    

    double md=0.0, ed=0.0, td=0.0, cd=0.0;

    for(int i=0; i<n; i++){
        md += abs(x[i] - y[i]);
        ed += abs(x[i] - y[i]) * abs(x[i] - y[i]);
        td += pow(abs(x[i] - y[i]), 3.0);
        cd = abs(x[i]-y[i]) > cd ? abs(x[i]-y[i]) : cd; 
    }
    
    ed = sqrt(ed);
    td = pow(td, 1.0/3.0);

    printf("%.6lf\n", md);
    printf("%.6lf\n", ed);
    printf("%.6lf\n", td);
    printf("%.6lf\n", cd);

    return 0;
}