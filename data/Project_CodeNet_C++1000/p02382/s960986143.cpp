#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=0; i<n; i++){
        cin >> y[i];
    }
    double D;
    
    //p=1
    D=0;
    for(int i=0; i<n; i++){
        D+=fabs(x[i]-y[i]);
    }
    printf("%.12lf\n",D);

    //p=2
    D=0;
    for(int i=0; i<n; i++){
        D+=(x[i]-y[i])*(x[i]-y[i]);
    }
    D=sqrt(D);
    printf("%.12lf\n",D);

    //p=3
    D=0;
    for(int i=0; i<n; i++){
        D+=fabs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
    }
    D=pow(D,1.0/3.0);
    printf("%.12lf\n",D);

    //p=inf
    D=0;
    int max;
    max=abs(x[0]-y[0]);
    for(int i=1; i<n; i++){
        if(max<abs(x[i]-y[i]))
            max=abs(x[i]-y[i]);
    }
    printf("%.12lf\n",(double)max);
    return 0;
    
}

