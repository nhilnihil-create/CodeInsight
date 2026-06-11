#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef   long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI 3.141592653589793238

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;
    x = x % p; 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 

ll inv(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 

ll sum[100005];

int main() 
{
    FAST;
    ll n=0,k=0;
    cin>>n>>k;
    for(int i=k;i>=1;i--)
    {
        sum[i]=(sum[i]+(i*power(k/i,n,A))%A)%A;
        ll x=2;
        while(x*i<=k)
        {
            sum[i]=(sum[i]-((sum[x*i]*inv(x,A))%A)+A)%A;
            x++;
        }
    }
    ll ans=0;
    for(int i=1;i<=k;i++)
    {
        //cout<<sum[i]<<' '<<i<<'\n';
        ans=(ans+sum[i])%A;
    }
    cout<<ans;
    return 0;
}