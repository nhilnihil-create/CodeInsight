
// **** WHEN THE GOING GETS TOUGH, THE TOUGH GETS GOING. ****

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]
typedef vector< int > vi;
typedef vector< ll > lvi;
typedef vector< vi > vvi;
typedef vector< lvi > lvvi;
typedef pair< int,int > ii;
typedef pair< ll,ll > lii;
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)//remember i is an iterator
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define ss second
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	ll k,T;
	cin>>k>>T;
	lvi d(k);
	for (int i = 0; i < k; ++i)
	{
		cin>>d[i];
	}
	while(T--)
	{
		ll n,x,m;
		cin>>n>>x>>m;
		x=x%m;
		lvi dd(k);
		ll M,q,sum1=0,v1=0;
		for (int i = 0; i < k; ++i)
		{
			dd[i]=d[i]%m;
			sum1+=dd[i];
			v1+=(dd[i]==0);
		}
		q=sum1/m;
		M=sum1%m;
		ll nc=(n-1)/k;
		ll ans=q*nc+((x+M*nc)/m)+v1*nc;
		ll curr_pos=(x+M*nc)%m;
		ll left=(n-1)%k;
		for(int i=0;i<left;i++)
		{
			ll pos=(curr_pos + dd[i])%m;
			if(pos<=curr_pos) ans++;
			curr_pos=pos;
		}
		cout<<n-ans-1<<endl;
	}
	return 0;
}