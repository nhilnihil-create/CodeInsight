#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int n,i,x[100]={0},y[100]={0};
    cin >> n;

       for(i=0;i<n;i++){
           cin >> x[i] ;
       }
       for(i=0;i<n;i++){
           cin >> y[i];
       }
    

    double p1,p2,p3,pinf,max=0;
    for(i=0;i<n;i++){
        p1+=abs(x[i]-y[i]);
        p2+=(pow(abs(x[i]-y[i]),2));
        p3+=pow(abs(x[i]-y[i]),3);
        pinf=abs(x[i]-y[i]);
        if(max<pinf){
            max=pinf;
        }
    }

    printf("%.6lf\n%.6lf\n%.6lf\n%.6lf\n",p1,sqrt(p2),cbrt(p3),max);

    return 0;
}