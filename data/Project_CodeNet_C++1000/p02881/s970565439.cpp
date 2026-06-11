#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+100;

ll n,m,T;

int main()
{
    scanf("%lld",&T);
    n = sqrt(T);
    if(n*n!=T)
    {
        for(ll i=n;i>=1;i--)
        {
            m = T/i;
            if(m*i == T)
            {
                printf("%lld\n",i + m -2);
                return 0;
            }
        }
    }
    printf("%lld\n",n*2-2);
    return 0;
}
