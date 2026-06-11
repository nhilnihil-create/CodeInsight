#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;  cin>>n;
    double x[n],y[n];

    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>y[i];

    double max=0;
    for(int i=0;i<n;i++){
        if(max<abs(x[i]-y[i])) max = abs(x[i]-y[i]);
    }


    double d1=0,d2=0,d3=0;
    for(int i=0;i<n;i++){
        d1 += abs(x[i]-y[i]);

        d2 += pow(abs(x[i]-y[i]),2);
        d3 += pow(abs(x[i]-y[i]),3);

    }
    d2 = pow(d2,1.0/2.0);
    d3 = pow(d3,1.0/3.0);

    printf("%8lf\n",d1);
    printf("%8lf\n",d2);
    printf("%8lf\n",d3);
    printf("%8lf\n",max);

    return 0;
}

