#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    double x,y,a,b,c,d,e;
    cin>>x>>y>>a>>b;
    c=(x-a)*(x-a);
    d=(y-b)*(y-b);
    e=sqrt((c+d));

    printf("%.8f\n",e);



    return 0;
}