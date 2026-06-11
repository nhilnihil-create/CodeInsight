#include<bits/stdc++.h>
using namespace std;
using ld = long double;
#define PI 3.14159265358979323846264338327950L
int main(){
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    ld rad=PI*2*((ld)h/12+((ld)m/60)/12-(ld)m/60);
    ld rsq=a*a+b*b-2*a*b*cosl(rad);
    printf("%20.20Lf\n",sqrt(rsq));

}