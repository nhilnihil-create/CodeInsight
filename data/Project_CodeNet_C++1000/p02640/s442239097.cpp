#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
bool isPrime[1000001];
ll power(ll a,ll b)
{
    ll result = 1;
    while(b>0)
    {
        if(b%2)
        {
            result = (a*result)%mod;
        }
        a = (a*a)%mod;
        b = b/2;
    }
    return result;
}
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
void sieve()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i*i<=1000000;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=1000000;j+=i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t,n;
    t = 1;
    for(int i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;
            bool c = 0;
            for(int i=0;i<=100;i++)
            {
                for(int j=0;j<=100;j++)
                {
                    if(i*2+j*4==y && i+j==x)
                    {
                        c = 1;
                        break;
                    }
                }
                if(c)
                {
                    break;
                }
            }
            if(c)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
    }
    return 0;
}