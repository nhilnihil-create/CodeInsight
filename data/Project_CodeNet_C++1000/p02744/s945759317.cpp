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
    ve<string> vec[10];
    ve<ll> dis[10];
    vec[0].pb("a");
    dis[0].pb(1);
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<vec[i-1].size();k++)
            {
                string te=vec[i-1][k];
                ll x=dis[i-1][k];
                if(x>=j)
                {
                    te.pb(j+'a');
                    if(x==j)
                        x++;
                    vec[i].pb(te);
                    dis[i].pb(x);
                }
            }
        }
    }
    ll k;
    cin>>k;
    sort(vec[k-1].begin(),vec[k-1].end());
    for(int i=0;i<vec[k-1].size();i++)
        cout<<vec[k-1][i]<<'\n';
    subt;
    return 0;
}