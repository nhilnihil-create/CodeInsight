#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    double ans = 0;
    double x[101]={}, y[101]={};
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=0; i<n; i++){
        cin >> y[i];
    }
    double p1=0, p2=0, p3=0, infi=0;
    ans=0;
        for(int i=0; i<n; i++){
            ans=fabs(x[i]-y[i]);
            p1 += ans;
            p2 += pow(ans,2);
            p3 += pow(ans,3);
            infi
            = max(infi,ans);
        }
    p2=sqrt(p2);
    p3=pow(p3,1.0/3.0);
    printf("%8f\n", p1);
    printf("%8f\n", p2);
    printf("%8f\n", p3);
    printf("%8f\n", infi);
    return 0;
}