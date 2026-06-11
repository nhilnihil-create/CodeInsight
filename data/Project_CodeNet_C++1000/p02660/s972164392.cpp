#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
int a[100005];
int main()
{
    long long n,now=1,ans=0;
    cin>>n;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                a[now]++;
                n/=i;
            }
            now++;
        }
    }
    if(n>1) a[now++]=1;
    for(int i=1;i<now;i++)
    {
        int t=1;
        while(a[i]>=t)
        {
            a[i]-=t;
            ans++;
            t++;
        }
        //cout<<ans<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}
