#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;
int main() {
    int n;
    while(1){
        cin >>n;
        double a[n];
        if(n==0) break;
        double b=0;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        b+=a[i];
    }
    double m=b/n;
    double c=0;
        for (int j=0; j<n; j++) {
            c += pow(m-a[j],2)/n;
        }
    printf("%.8f\n",sqrt(c) );
    }
}
