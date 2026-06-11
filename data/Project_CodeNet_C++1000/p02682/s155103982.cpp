//>>>>>>>>>>>>>>>>>>>>>>>>>>JAI BAJRANG BALI<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
#define HARSH_JUDGE
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define db(x)                   cout<<#x<<"="<<x<<'\n'
#define db2(x,y)                 cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define ll long long
#define ld long double
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ull unsigned long long
#define setbits(x)      __builtin_popcountll(x)
#define str string
#define bhaag_basanti ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define forr(i,n,a) for(ll i=n;i>=a;i--)
#define cases   long long t;cin>>t;while(t--)
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define sp(x,y)         fixed<<setprecision(y)<<x
#define nl '\n'
#define sz(x) ((int)(x).size())
const int mod = (int) 1e9 + 7 ;
const int MOD = (int) 998244353 ;
const ll INF = 1e18 ;
const ll N = 1e5 + 5;
#define printall(a) fo(i,0,a.size()) cout<<a[i]<<" "; cout<<endl;



typedef vector<int> vi;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<ll, int> mli;
typedef map<char, int> mci;
typedef vector<long long> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
typedef vector<vector<int> > vv;

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b)
{

	return a.ss < b.ss;
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>TOR DE DUSHMAN KI NALI<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//


void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll ans = min(a, d);
	d -= ans;
	if (d)
	{
		d = max(0LL, d - b);
	}
	ans -= d;
	cout << ans;


	return;
}


int main()
{
	bhaag_basanti
#ifndef HARSH_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	ll t = 1;
	// cin >> t;
	// clock_t timest = clock();
	// cerr << "[Executes in " << (double)(clock() - timest) / CLOCKS_PER_SEC << "s]" << endl;
	while (t--)
	{
		solve();

	}
}