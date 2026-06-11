#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,x;
    cin>>a>>b>>x;
    if(2*x<=a*a*b){
        double c=2.0*x/a/b;
        printf("%.7f\n",atan(b/c)/(2*M_PI)*360.0);
    }else{
        double c=2.0*b-2.0*x/a/a;
        printf("%.7f\n",atan(c/a)/(2*M_PI)*360.0);
    }
}