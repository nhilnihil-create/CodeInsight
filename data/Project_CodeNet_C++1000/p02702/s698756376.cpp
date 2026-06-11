
// Problem : D - Multiple of 2019
// Contest : AtCoder - AtCoder Beginner Contest 164
// URL : https://atcoder.jp/contests/abc164/tasks/abc164_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,b,a) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define cs(ans) setprecision(10)<<fixed<<ans
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ld pii=3.14159265359;
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() 
{
	#define int ll
	ios_base::sync_with_stdio(0); cin.tie(0);    
	string str;
	cin>>str;
	int N=sz(str);
	vl m(2019);
	m[str[0]-'0']++;
	ll ans=0;
	FOR(x,1,N)
	{
		int nb=str[x]-'0';
		// dp[nb]++;
		vl v(2019);
//		v[0]=1;
		v[nb]++;
		F0R(y,2019)
		{
			if(m[y]!=0)
			{
				int rem=(y*10+nb)%2019;
				// cout<<nb<<endl;
				// cout<<x<<' '<<y<<' '<<rem<<endl;;
				if(rem==0)ans+=m[y];
				v[rem]+=m[y];
//				if(y==0)
			}
		}
//		ans+=v[0];
		F0R(x,2019)
			m[x]=v[x];
	}
	cout<<ans<<endl;
	return 0;
	//CHECK CORNER CASES
}
// read the question correctly (ll vs int)
// template by bqi343


