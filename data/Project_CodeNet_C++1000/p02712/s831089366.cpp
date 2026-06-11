#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int n;
    double sum;
    scanf("%d",&n);
    sum=0;
    for(int i=1;i<=n;i++)
    {
        if(i%3==0||i%5==0)
            continue;
        else
            sum=sum+i;
    }
    printf("%.0f\n",sum);
    return 0;
}
