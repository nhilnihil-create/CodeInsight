#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//adds two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set]
//(2)set.order_of_key(k)[count of elements strictly less than k]
#define ll long long
#define ld long double
#define vv vector
#define pp pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
typedef pair<ll, ll> pll;
typedef vv<bool> vbool;
typedef vv<ll> vll;
typedef vv<ld> vld;
typedef vv<pll> vpll;
#ifdef LOCAL
#include "prettyprint.hpp"
#define LG(args...)                           \
{                                             \
	string _s = #args;                        \
	replace(_s.begin(), _s.end(), ',', ' ');  \
	stringstream _ss(_s);                     \
	err(istream_iterator<string>(_ss), args); \
	cerr << endl;                             \
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "(" << *it << ":" << a << ") ";
	err(++it, args...);
}
#define fastio
#else
#define LG(...)
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define endl "\n"
#endif
//:::::::::::::::::::::::::::::::::::::::::::::
const ll INF = 9e18;
const ll MOD = 1e9 + 7;

int main(){
	fastio;
	 ll n,a,b;
	 cin>>n>>a>>b;
	 if(a > b)
	 	swap(a,b);
	 ll ans;
	 if((b-a)%2 == 0)
	 	ans = (b-a)/2;
	 else{
	 	ll t1=0, t2=0;
	 	t1 += a-1;
	 	t1++;
	 	t1 += (b-a-1)/2;

	 	t2 += n-b;
	 	t2++;
	 	t2 += (b-a-1)/2;
	 	ans = min(t1,t2);
	 }
	 cout<<ans;
}