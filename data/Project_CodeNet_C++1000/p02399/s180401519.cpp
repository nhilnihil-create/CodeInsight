#include<iostream>
#include <stdio.h>
using namespace std;
int main(){
    int a,b,d,r;
    double f;
    cin>>a>>b;
    d=a/b;
    r=a%b;
    f=1.00000000*a/b;
    printf("%d %d %.8lf\n",d,r,f);
    return 0;
}
