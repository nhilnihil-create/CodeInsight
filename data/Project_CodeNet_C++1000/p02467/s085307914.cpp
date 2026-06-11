#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll num[1000010], prime[1000010], n_prime=0;

ll Prime()
{
    ll i, j;
    for(i=0; i<1000010; i++)
        prime[i]=1;
    prime[0]=prime[1]=0;
    for(i=2; i<1000010; i++)
    {
        if(prime[i])
        {
            num[++n_prime]=i;
            for(j=2*i; j<1000010; j=j+i)
                prime[j]=0;
        }
    }
}

int main()
{
    ll n, i, j;
    Prime();
    while(scanf("%lld", &n)!=EOF)
    {
        printf("%lld:", n);
        for(i=1; i<n_prime && num[i]<=sqrt(n); i++)
        {
            if(n<num[i])
                break;
            if(n%num[i]==0)
            {
                while(n%num[i]==0)
                {
                    n=n/num[i];
                    printf(" %lld", num[i]);
                }
            }
        }
        if(n>1)
            printf(" %lld", n);
        printf("\n");
    }
    return 0;
}