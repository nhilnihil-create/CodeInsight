#include <bits/stdc++.h>
#define lli long long int
#define vec2 vector<vector<lli>>
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("explicit.in","r",stdin);freopen("explicit.out","w",stdout)
#define pll pair <lli,lli>
#define vll vector <lli>
#define vpll vector <pll>
#define f first
#define s second
#define pb push_back
#define priq priority_queue
#define unm unordered_map
#define pf push_front
#define minii LLONG_MAX
#define all(x) x.begin(), x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define ld double
#define eb emplace_back
const long double pi = 3.1415926535898;
const lli mod=1e9+7;
//const lli mod=100000000;
using namespace std;
lli lcm (lli a, lli b) {return ((a*b)/__gcd(a,b));}
lli modpower (lli a,lli b)
{
    if(b==0) return 1;
    lli c=modpower(a,b/2)%mod;
    if (b%2) return (((a*c)%mod)*c)%mod;
    else return (c*c)%mod;
}
lli power (lli a,lli b)
{
    if(b==0) return 1;
    lli c=power(a,b/2);
    if (b%2) return (a*c*c);
    else return c*c;
}
bool prime (lli k)
{
    if (k==1||k==0) return 0;
    bool flag=1;
    lli a=sqrt(k);
    for (int i=2;i<=a;i++)
    {
        if (k%i==0)
        {flag=0;break;}
    }
    return flag;
}
lli b[10000007];
lli sieve (int n)
{
    for (int i=2;i<n;i++)
    {
        if (b[i]==0)
        {
            for (int j=i;j<=n;j+=i)
            {
                if (b[j]==0)
                {
                    b[j]=i;
                }
            }
        }
    }
    return 0;
}
lli find(lli n)
{
    lli sum=0,ans=1;
    vll v;
    lli z;
    while (1)
    {
        if (n==1)
        {
            break;
        }
        sum=0;
        z=b[n];
        //cout<<n<<" "<<b[n]<<"\n";
        while (n%z==0)
        {
            n/=z;
            sum++;
        }
        v.pb(sum);
    }
    for (int i=0;i<v.size();i++)
    {
        ans*=(v[i]+1);
    }
    //cout<<ans<<"\n";
    return ans;
}
int main()
{
    fio;
    sieve(10000000);
    lli n;
    cin>>n;
    lli ans=1;
    for (int i=2;i<=n;i++)
    {
        //cout<<i<<"\n";
        ans+=i*(find(i));
        //cout<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}
