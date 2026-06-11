#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef   long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define B 998244353ll
#define C 1000000000000000001ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
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
#define PI 3.14159265358979323

int main() 
{
    FAST;
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=1;
    for(int i=0;i<n-1;i++)
    	if(s[i]!=s[i+1])
    		ans++;
    while(ans>1 && k>0)
    {
    	if(ans>2)
    		ans-=2;
    	else
    		ans--;
    	k--;
    }
    cout<<n-ans;
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}