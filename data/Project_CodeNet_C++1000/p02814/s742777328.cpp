#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define D 1000000000ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI acos(-1)
#define subt cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n"

ll gcd(ll a,ll b)
{
    if(a%b==0)
        return b;
    else 
        return gcd(b,a%b);
}

int main() 
{
    FAST;
    ll n,m;
    cin>>n>>m;
    ll a[n];
    ll g=1,l=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=a[i]/2;
        if(i==0)
            g=1;
        else
            g=gcd(l,a[i]);
        l=l*a[i];
        l=l/g;
        if(l>m)
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
        if((l/a[i])%2==0)
        {
            cout<<0;
            return 0;
        }
    ll ans=(m/l)-(m/(2ll*l));
    cout<<ans;
    subt;
    return 0;
}