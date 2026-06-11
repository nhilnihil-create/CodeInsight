#include <bits/stdc++.h>
using namespace std;
long long s;
int main()
{
    scanf("%lld",&s);
    if (s<=1000000000)
    {
        printf("%d %d %d %d %lld %d\n",0,0,0,1,s,0);
        return 0;
    }
    int t=sqrt(s);
    while (1LL*t*t<s) ++t;
    for (int i=0;i<1000;i++)
        for (int j=0;j<1000;j++)
        {
            int c=t+i,d=t+j;
            if (c>1000000000||d>1000000000) continue;
            long long x=1LL*c*d-s;
            if (x==0LL)
            {
                printf("%d %d %d %d %d %d\n",0,c,d,0,d,c);
                return 0;
            }
            for (int i=1;1LL*i*i<=x;i++)
                if (x%i==0&&c>i&&d>x/i)
                {
                    int a=c-i;
                    int b=d-x/i;
                    printf("%d %d %d %d %d %d\n",0,a,b,0,d,c);
                    return 0;
                }
        }
    return 0;
}