#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define all(X) X.begin(),X.end()

// for pair comparison function(ascending order) use return (i1.ff < i2.ff);

/* string operations :
   str.substr (x,y) : returns a substring str[x],str[x+1],...str[x+y-1]
   str.substr (x) : returns a substring str[x],... end of string
   str.find(qtr) : returns the first occurenece of qtr in str.
   builtin functions :
   __builtin_popcount(n) : no. of set bits in n.
   __builtin_parity(n) : parity of no. of set bits
   __builtin_clz(n) : no. of leading zeros before 1
   __builtin_ctz(n) : no of zeros from last to first occurrence of 1
*/

const int M = (1<<20)+5;
const int md = 1e9+7;

ll pwr(ll a,ll n,ll m)
{
	ll p=1;
	while(n>0)
	{
		if(n%2==1)
			p=(p*a)%m;
		a=(a*a)%m;
		n=n/2;
	}
	return p;
}

ll binlen(ll a)
{
	ll v = 0;
	for(ll i=0;i<61;++i)
	{
		v += (1ll<<i);
		if(a<=v) return i;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	cout << (n-1)/2 << endl;
}