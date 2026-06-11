#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define D 100000000000000ll
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
 
int main() 
{
    FAST;
    ll n,m;
    cin>>n>>m;
    if(n%2==1)
        for(int i=1,j=n,k=0;i<j && k<m;i++,j--,k++)
            cout<<i<<' '<<j<<'\n';
    else
    {
        int k=0;
        for(int i=1,j=n/2;i<j && k<m;i++,j--,k++)
            cout<<i<<' '<<j<<'\n';
        for(int i=(n/2)+2,j=n;i<j && k<m;i++,j--,k++)
            cout<<i<<' '<<j<<'\n';
    }
    subt;
    return 0;
}