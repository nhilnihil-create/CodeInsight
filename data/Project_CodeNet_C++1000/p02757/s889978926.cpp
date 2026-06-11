#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef long double ld;
#define A 1000000007ll
#define D 100000000000000ll
#define B 998244353ll
#define C 1000000000000000000ll
#define M 4000
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define pf push_front
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

ll po[10005];

int main() 
{
    FAST;
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll pre[n+1];
    pre[n]=0;
    ll ans=0;
    ll x=1;
    for(int i=n-1;i>=0;i--)
    {
        pre[i]=(pre[i+1]+((ll)(s[i]-'0')*x))%p;
        x=(x*10)%p;
    }
    if(p==2 || p==5)
    {
        if(p==2)
            for(int i=0;i<n;i++)
                if(s[i]=='0' || s[i]=='2' || s[i]=='4' || s[i]=='6' || s[i]=='8')
                    ans+=i+1;
        if(p==5)
            for(int i=0;i<n;i++)
                if(s[i]=='5' || s[i]=='0')
                    ans+=i+1;
    }
    else
    {
        for(int i=n;i>=0;i--)
        {
            ans+=po[pre[i]];
            po[pre[i]]++;
        }
    }
    cout<<ans;
    subt;
    return 0;
}