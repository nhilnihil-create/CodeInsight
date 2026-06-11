#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >>n;
    int x[n],y[n];
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }
    for (int i=0; i<n; i++) {
        cin >> y[i];
    }
    double a,b,c,d;
    a=b=c=d=0;
    for (int i=0; i<n; i++) {
        a+= fabs(x[i]-y[i]);
        b+= pow(x[i]-y[i],2);
        c+= pow(fabs(x[i]-y[i]),3);
        d = max(d,fabs(x[i]-y[i]));
    }
    printf("%.8f\n",a);
    printf("%.8f\n",sqrt(b));
    printf("%.8f\n",pow(c,1.0*1/3));
    printf("%.8f\n",d);
}

