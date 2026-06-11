#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
const int N=2005+5;

int mod=1000000007 ;
ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}
ll fac[N];
ll inv(ll x)
{
    return fastpow(x,mod-2);

}
ll ncr(ll n, ll r)
{
return mul(inv(fac[r]),mul(fac[n],inv(fac[n-r])));

}


int main()
{
    FIO
    fac[0]=1;
    for(int i=1;i<N;i++)
        fac[i]=mul(fac[i-1],i);
    int n, k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        if(n-k-i+1<0)
            cout<<"0\n";
        else
        {
            cout<<mul(ncr(n-k+1,i),ncr(k-1,k-i))<<endl;

        }


    }
      return 0;
}
