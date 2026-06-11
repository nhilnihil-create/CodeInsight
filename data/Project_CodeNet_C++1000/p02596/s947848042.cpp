#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main ()
{
    int x;
    scanf ("%d",&x);
    if(x%2==0||x%5==0)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        long long  a=0;
        for(int i=0; ;i++)
        {
            a=(a*10+7)%x;
            if(a%x==0)
            {
                printf ("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}