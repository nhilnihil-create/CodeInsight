#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int t[101];
    long long sum=1000;
    long long f;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<n;i++)
    {
        f=0;
        if(t[i]<t[i+1])
            f=sum/t[i];
        sum+=(t[i+1]-t[i])*f;
    }
    printf("%lld\n",sum);
    return 0;
}
