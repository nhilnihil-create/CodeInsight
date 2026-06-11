#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n,x[100],y[100];
    double p1=0,p2=0,p3=0,pm,pmax=0;

    cin >> n;
    for(int i=0; i<n; i++)cin >> x[i];
    for(int i=0; i<n; i++)cin >> y[i];

    for(int i=0; i<n; i++)p1 += 1.0*fabs(x[i]-y[i]);
    
    for(int i=0; i<n; i++)p2 += 1.0*pow(x[i]-y[i],2);
    p2 = sqrt(p2);

    for(int i=0; i<n; i++)p3 += 1.0*pow(fabs(x[i]-y[i]),3);
    p3 = pow(p3,1.0/3.0);

    for(int i=0; i<n; i++){
        pm = 1.0*fabs(x[i]-y[i]);
    	if(pm-pmax > 0) pmax = pm;
    }

    printf("%f\n%f\n%f\n%f\n",p1,p2,p3,pmax);
    //printf("test %f\n",pow(8,1.0/3.0));

    return 0;
}