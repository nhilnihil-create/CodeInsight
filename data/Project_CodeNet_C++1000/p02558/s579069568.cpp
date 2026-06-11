#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() int t;cin>>t;for(int test=1;test<=t;test++)
#define pb push_back
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()

template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }

const ll MOD = 1000000007;
ll mod( ll n, ll m=MOD ){ n%=m,n+=m,n%=m;return n; }

const int MAXN = 1e5+5;
const int LOGN = 21;
const ll INF = 1e14;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

template<class T1, class T2> void add( T1 &x, T2 y, ll m = MOD )
{
	x += y;
	if( x >= m )
		x -= m;
}

template<class T1, class T2> void sub( T1 &x, T2 y, ll m = MOD )
{
	x -= y;
	if( x < 0 )
		x += m;
}

int main() 
{
	#ifdef gupta_samarth
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio();

	int n,q;
	cin>>n>>q;

	dsu d(n);
	while(q--)
	{
		int t,u,v;
		cin>>t>>u>>v;

		if( t == 0 )
		{
			d.merge(u,v);
		}
		else
		{
			puts( d.same(u,v) ? "1" : "0" );
		}

	}

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
