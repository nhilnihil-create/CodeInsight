#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<=((int)n);++i)
#define rev(i,n,j) for(int i=(n);i>=((int)j);--i)
typedef long long int ll;
#define int long long int
const ll INFL=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int mod=998244353;
#define endl "\n"
#define mem(a,val) memset(a,val,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define pb push_back
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define readmat(a, n, m) int a[n + 5][m + 5] = {}; rep(i, 1, n) {rep(j, 1, m) cin >> a[i][j];}
#define printmat(a, n, m) rep (i, 1, n) {rep (j, 1, m) cout << a[i][j] << " "; cout << endl;} cout << endl;
#define printarr(a, n) rep(i, 1, n) cout << a[i] << " "; cout << endl;
typedef std::map< int,int> mii;
typedef std::vector< int > vi;
typedef std::vector< vi > vvi;
typedef std::pair< int,int > ii;
using namespace std;
#define cerr cout
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);}
const int N = 1e6+5, M = N;
vector <int>g[N];

ll power(ll a, ll b)	//a is base, b is exponent
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2 == 1)
		return (power(a,b-1)*a)%mod;
	ll q = power(a,b/2);
	return (q*q)%mod;
}

void solve()
{
	int n,s;
	cin>>n>>s;
	int a[n+5];
	for(int i = 1; i <=n; ++i) 
	{
		cin>>a[i];
	}

	int dp[n+5][s+5];
	mem(dp,0);
	dp[0][0]=power(2,n);

	int inv=power(2,mod-2);

	for(int i = 1; i <=n; ++i) 
	{
		for(int j =0; j <=s; ++j) 
		{
			if (j<a[i])
			{
				dp[i][j]=dp[i-1][j];
				continue;
			}
			dp[i][j]=(dp[i][j]+dp[i-1][j]+(dp[i-1][j-a[i]]*inv)%mod)%mod;
		}
	}


	cout<<dp[n][s]<<endl;
  

}

signed main()
{
  FAST;
#ifdef LOCAL
    freopen("C:\\Users\\hp\\Documents\\input.txt", "r", stdin);
    freopen("C:\\Users\\hp\\Documents\\output.txt", "w", stdout);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
#endif

solve();

#ifdef LOCAL
    end = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    cout<<endl;
    cout << "\nElapsed Time: " << elapsed_time << "ms\n";
#endif

return 0;

}