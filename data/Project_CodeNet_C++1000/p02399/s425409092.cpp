#include<stdio.h>

using namespace std;

int main(){

    int a,b;
    double a_d,b_d;
    int d,r;
    double f;
    

    scanf("%d %d",&a,&b);
    a_d=static_cast<double>(a);
    b_d=static_cast<double>(b);
    d=(a/b);
    r= (a%b);
    f= (a_d / b_d);
    printf("%d %d %.5f\n",d,r,f);
    //printf("%d %d\n",d,r);

    return 0;
    
}
