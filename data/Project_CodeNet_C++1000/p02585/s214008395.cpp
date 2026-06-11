//Nihal Mittal - nihal_47
//Strike First , Strike Hard , No Mercy !!

/**⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣰⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣧⢀⠀⠀⠀⠀
⠀⠀⠀⣿⣿⣿⠋⠀⠀⠀⠀⠀⠙⠀⠙⣿⣿⣿⣷⢳⢀⠀⠀⠀
⠀⠀⣠⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⢀
⠀⠀⣸⣿⣿⣿⠸⠀⠀⠀⠒⠒⠒⠐⠀⠀⢿⣿⣿⣿⣿⣿⠀⠀
⠀⣴⣿⣿⣿⡿⠀⠒⣋⣙⡒⢰⠀⠤⣖⠒⢾⣿⣿⣿⣿⣧⠀⠀
⢺⣿⣿⣿⣿⢀⠀⠀⠉⠉⠉⠸⠀⡇⠉⠉⠀⢿⣿⣿⣿⣄⠀⠀
⠀⠙⣿⣿⣧⢻⠀⠀⠀⠀⠀⠠⠀⠰⠀⠀⠀⣸⠸⣿⣿⠿⠰⠀
⠀⠀⠀⠹⣿⣿⣿⣷⠀⡠⠙⣲⣔⣅⢡⣰⣷⣿⣿⣿⣧⠀⠀⠀
⠀⠀⠀⣼⣿⣿⣿⣿⠀⡿⠭⠭⠭⠭⢿⠀⣿⢻⣿⣿⠃⠀⠀⠀
⠀⠀⠀⠙⠛⣿⢻⠹⣿⠐⠙⠛⠟⠉⢀⣴⡟⢿⣿⡏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⡟⠀⠀⠻⣦⣤⣶⠾⠋⠀⠀⠁⡦⢄⢀⠀⠀⠀
⠀⠀⠀⠀⡠⠁⡇⠑⢄⠀⠀⠀⠀⠀⠀⠔⠀⠀⠁⠀⠀⠀⠉⠁
⠀⠔⠊⠁⠀⠀⣇⠀⠀⠀⠑⡤⠤⢎⠁⠀⠀⡘⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢢⠠⠀⡠⢆⠀⠀⡠⠙⢄⠀⡸⠀
**/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define mk make_pair
#define pb push_back
#define in insert
#define se second
#define fi first
#define mod 1000000007
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define all(v) (v).begin(),(v).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define pii pair<ll,ll>
#define vi(x) vector<x>
#define maxn 100005
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;
using namespace __gnu_pbds;

signed main()
{
    fast;
 
    ll n,i,j,k,ans=-LLONG_MAX;
    cin>>n>>k;
    ll p[n+2],c[n+2];
    for(i=1;i<=n;i++) cin>>p[i];
    for(i=1;i<=n;i++) cin>>c[i];

    for(i=1;i<=n;i++)
    {
    	vector<ll> v;
    	ll tot=0;
    	ll cur = i;
    	while(1)
    	{
    		cur = p[cur];
    		v.pb(c[cur]);
    		tot += c[cur];
    		if(cur==i) break;
    	}
    	ll sum=0;
    	ll si = v.size();
    	for(j=0;j<si;j++)
    	{
    		if(j+1 > k) break;
    		sum += v[j];
    		ll ha = sum;
    		if(tot>0)
    		{
    			ha += ((k-(j+1))/si) * tot;
    		}
    		ans = max(ans,ha);
    	}
    }
    cout<<ans;

}