#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
int main()
{
    double a,b,c,d,n,m;
    std::cin >> a >> b >> c >> d;
    if(a>c){
        if(b>d){
            m=(a-c)*(a-c)+(b-d)*(b-d);
            n=sqrt(m);
            printf("%.8f", n);
        }else if(b<d){
            m=(a-c)*(a-c)+(d-b)*(d-b);
            n=sqrt(m);
            printf("%.8f", n);
        }else{
            m=a-c;
            //n=sqrt(m);
            printf("%.8f", m);
        }
    }else if(a<c){
        if(b<d){
            m=(c-a)*(c-a)+(d-b)*(d-b);
            n=sqrt(m);
            printf("%.8f", n);
        }else if(b>d){
            m=(c-a)*(c-a)+(b-d)*(b-d);
            n=sqrt(m);
            printf("%.8f", n);
        }else{
            m=c-a;
            //n=sqrt(m);
            printf("%.8f", m);
        }
    }else if(a==c){
        if(b<d){
            printf("%.8f", d-b);
        }else{
            printf("%.8f", b-d);
        }
    }
    return 0;
}

//printf("%.8f", n);