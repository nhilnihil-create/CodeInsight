///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {			cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };


bool seive[1010000];
vi prime;

void seiveGen(int limit) {
	limit += 100;
	int sqrtn = sqrt(limit);
	for(int i = 3; i <= sqrtn; i += 2) {
			if(!seive[i>>1]) {
					for(int j = i * i; j < limit; j += i + i) {
							seive[j>>1] = 1;
					}
			}
	}
	prime.PB(2);
	for(int i = 3; i < limit; i += 2) {
			if(!seive[i>>1]) prime.PB(i);
	}
}

map<ll, int> cnt;

set<ll> factorize ( ll n )
{
	set<ll> ret;
	for ( auto p : prime ) {
		if ( 1LL * p * p > n || n == 0 ) break;

		if ( n % p == 0 ) {
			ret.insert ( p );

			while ( n % p == 0 ) {
				n /= p;
				cnt[p]++;
			}
		}
	}

	if ( n > 1 ) {
		cnt[n]++;
		ret.insert ( n );
	}

	return ret;
}


ll mypow ( ll a, ll b )
{
	ll ret = 1;
	for ( int i = 0; i < b; i++ ) {
		ret *= a;
	}

	return ret;
}

map<ll, bool> vis;

int main()
{
	optimize();

	seiveGen(1e6);

	ll n;
	cin >> n;
	set<ll> fact = factorize(n);

	for ( auto u : fact ) {
		for ( int i = 1; i <= cnt[u]; i++ ) {
			vis[mypow(u, i)] = 1;
		}
	}

	vl v;
	for ( ll i = 1; i <= n; i++ ) {
		if ( i * i > n ) break;
		if ( n % i == 0 ) {
			if ( vis[i] ) v.PB ( i );
			if ( vis[n/i] == 1 && n / i != i ) v.PB ( n/ i );
		}
	}

	sort ( all ( v ) );

	int ans = 0;
	for ( auto u : v ) {
		if(n == 0) break;
		if ( n % u == 0 ) {
			n /= u;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}















