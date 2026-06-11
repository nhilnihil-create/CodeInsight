#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,t,x;
    scanf("%d %d %d",&n,&x,&t);
    if(n%x==0)
    {
        printf("%d",(n/x)*t);
    }
    else{
        printf("%d",(n/x+1)*t);
    }
    return 0;
}
