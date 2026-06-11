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
        int x,n;
        cin>>x>>n;
        int arr[n];
        int dp[205]= {0};
        x = x+100;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            dp[arr[i]+100]++;
        }
        int mini = INT_MAX,l=0;
        for(int i=0;i<205;i++)
        {
            if(dp[i]==1)
            {
                continue;
            }
            if(mini>abs(i-x))
            {
                mini = abs(i-x);
                l = i;
            }
        }
        cout<<l-100;
    }
    return 0;
}