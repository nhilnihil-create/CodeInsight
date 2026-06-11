#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,k=0,l,x;
    scanf("%lld\n",&n);

    x=n+1;

    for(i=0;i<n;i++)
    {
        scanf("%lld",&j);
        if(j<x)
        {
            k++;
            x=j;
        }
    }
    printf("%lld",k);
    return 0;
}
