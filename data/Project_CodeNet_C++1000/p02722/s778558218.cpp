#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int is(int n,int i)
{
    while(n%i==0)
        n=n/i;
    return n%i==1;
}
int solve(int n)
{
    int ans=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n=n/i;
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(n!=1)
        ans*=2;
    return ans;
}
int32_t main() {
    nitin;
    int n;
    cin>>n;
    int ans=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            {ans+=is(n,i);
        if(i*i!=n)
        ans+=is(n,n/i);}
    }
    ans+=solve(n-1);
    cout<<ans<<endl;
    return 0;
}