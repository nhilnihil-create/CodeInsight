#include<iostream>
using namespace std;

long long s,x,y,x2,y2;

int main()
{
    scanf("%lld",&s);
    x=1e9;y=1;
    y2=s/x;
    if(s%x!=0) y2++;
    x2=x*y2-s;
    printf("0 0 %lld %lld %lld %lld",x,y,x2,y2);

    return 0;
}