#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define f              first
#define s              second
#define gc getchar_unlocked
#define fo(i,start,end) for(int i=start;i<end;i++)
#define FORR(i,end,start) for(int i=end-1;i>start;i--)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf std::numeric_limits<double>::infinity()
//#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define INPUT(a,n) fo(i,0,n) cin>>a[i];
#define INPUT2d(a,n,k) fo(i,0,n) fo(j,0,k) cin>>a[i][j];
#define mk(a,n,type)  type *a=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define SIZE 100005
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

void solve() {
  ll n,ans=0; cin>>n;
  ll a[n];
  INPUT(a,n)
  sort(a,a+n);
  fo(p,0,n) fo(j,p+1,n) fo(k,j+1,n){
    if(a[p]+a[j]>a[k] && a[p]!=a[j] && a[j]!=a[k]) ++ans;
  }
  cout<<ans<<'\n';
  
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif


    // ll t = 1;
    // cin >> t;
    // while(t--) {
      solve();
    //}

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

