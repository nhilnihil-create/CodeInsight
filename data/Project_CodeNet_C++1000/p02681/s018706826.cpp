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
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()-1)
        {
            cout<<"No";
        }
        else
        {
            bool x = 0;
            for(int i=0;i<s1.size();i++)
            {
                if(s1[i]!=s2[i])
                {
                    x = 1;
                    break;
                }
            }
            if(!x)
            {
                cout<<"Yes";
            }
            else
            {
                cout<<"No";
            }
        }
    }
    return 0;
}