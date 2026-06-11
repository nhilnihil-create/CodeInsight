#include <bits/stdc++.h>
using namespace std;
double sa(double a,double   b){
    return max(a,b)-min(a,b);
}
int main(void){
    int A,B,H,M;
    cin >> A >> B >> H >> M;
    long double pi=2.0*asin(1.0);
    long double rad=pi/180.0*(sa((60.0*H+M)/2.0,M*6.0));
    long double len=sqrt(A*A+B*B-2*A*B*cosl(rad));
    printf("%.10Lf",len);
}