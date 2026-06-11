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
        sieve();
        cin>>n;
        int arr[n];
        int z;
        unordered_map <int,int> mp,mp2;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            mp[arr[i]]++;
        }
        vector <int> v;
        for(auto i = mp.begin();i!=mp.end();i++)
        {
            v.push_back(i->first);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            for(int j=2;j<=1000000;j++)
            {
                if(v[i]*j>1000000)
                {
                    break;
                }
                mp2[v[i]*j] = 1;
            }
        }
        int cnt = 0;
        for(int i=0;i<v.size();i++)
        {
            if(mp[v[i]]>=2)
            {
                continue;
            }
            if(!mp2[v[i]])
            {
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}