#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool prime[1000006];
ll d[1000006];
void sieve()
{
    for(int i=1; i<=1000000; i++)d[i]= 1;
    for(int i=2; i<=1000000; i++)
    if(!prime[i])
    {
        d[i]*= 2;
        for(int j=2*i; j<=1000000; j+= i)
        {
            prime[j]= 1;
            int x= j, c= 1;
            while(!(x%i))x/= i, c++;
            d[j]*= c;
        }
    }
    return;
}
int main()
{
    sieve();
    int n;
    scanf("%d", &n);
    ll res= 0;
    for(int i=1; i<n; i++)res+= d[i];
    printf("%lld\n", res);
    return 0;
}
