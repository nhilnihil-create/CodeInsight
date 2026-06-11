/*author - Ashutosh Chitranshi*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define watch3(x,y,z) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<"\n"
#define pow2(x) ((x)*(x))
#define ll long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
#define mod 1000000007
#define ordered_set tree<pair<ll,ll>,null_type,less<pair<ll,ll>>,rb_tree_tag,tree_order_statistics_node_update>
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
#define mp make_pair
#define ff first
#define ss second
#define null NULL
#define all(c) (c).begin(),(c).end()
#define nl "\n"
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
typedef pair< int,int > ii;
typedef pair< ll,ll> pll;
typedef map< ll,ll> mll;
typedef map< int,int> mii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x;
    cin >> x;
   	ll y = x;
    int c = 1;
  	while(true)
    {
	    if(__gcd(y,360ll) == 360ll)
	    {
	       cout << c << nl;
	       break;
	    }
	    y += x;
	    c++;
    }
    return 0;
}