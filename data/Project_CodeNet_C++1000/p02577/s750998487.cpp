#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char a[200001];
int n;
int main()
{
    scanf("%s",a);
    for(int i=0; i<200001; i++)
    {
        if(a[i]==0)
        {
            continue;
        }
        else{
            n+=a[i]-48;
        }
    }
   // printf("%d\n",n);
    if(n%9==0)
    {
        printf("Yes");
    }
    else{
        printf("No");
    }

    return 0;
}
