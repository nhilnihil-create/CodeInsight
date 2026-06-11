#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[200001];
int n,k;
long long m;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(k>a[i])
        {
            m+=k-a[i];
        }
        else{
            k=a[i];
        }
    }
    printf("%lld",m);
    return 0;
}
