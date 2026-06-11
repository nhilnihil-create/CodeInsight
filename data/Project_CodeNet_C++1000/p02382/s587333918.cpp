#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main(void){
    int dim;
    cin >> dim;
    double vx[dim], vy[dim];
    for(int i=0; i<dim; i++) cin >> vx[i];
    for(int i=0; i<dim; i++) cin >> vy[i];
    
    double d1 = 0, d2 = 0, d3 = 0, di = 0, d = 0;
    
    for(int i=0; i<dim; i++){
        d1 += abs(vx[i] - vy[i]);
        d2 += pow((vx[i] - vy[i]), 2);
        d3 += pow(abs(vx[i] - vy[i]), 3);
        d = abs(vx[i] - vy[i]);
        if(i==0){
            di = d;
        }else{
            if(di < d) di = d;
        }
    }
    d2 = sqrt(d2);
    d3 = pow(d3, 1.0/3.0);

    printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n", d1, d2, d3, di);
    
    return 0;
}