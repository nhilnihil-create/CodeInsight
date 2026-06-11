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
    ll n;
    cin>>n;
    ll a,x;
    x=LLONG_MIN;
    multiset<ll> s;
    n=powl(2,n);
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	s.insert(a);
    	x=max(x,a);
    }
    ve<ll> d;
    d.pb(x);
    auto p=s.find(x);
    s.erase(p);
    while(s.size()!=0)
    {
    	ll co=d.size();
    	for(int i=0;i<co;i++)
    	{
    		p=s.lb(d[i]);
    		if(p==s.begin())
    		{
    			cout<<"No";
    			cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    			return 0;
    		}
    		p--;
    		d.pb((*p));
    		s.erase(p);
    	}
    }
    cout<<"Yes";
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}