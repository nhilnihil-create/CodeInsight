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
#define C 8000000000000000000ll
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

int main() 
{
    FAST;
    ll a,b,m;
    cin>>a>>b>>m;
    ll r[a+1],mi[b+1];
    ll x,y,c;
    ll mi1=C,mi2=C,ans=0;
    for(int i=1;i<=a;i++)
    {
        cin>>r[i];
        mi1=min(mi1,r[i]);
    }
    for(int i=1;i<=b;i++)
    {
        cin>>mi[i];
        mi2=min(mi2,mi[i]);
    }
    ans=mi1+mi2;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>c;
        ans=min(ans,r[x]+mi[y]-c);
    }
    cout<<ans;
    subt;
    return 0;
}