/** Author: Dwai
 *  Omae wa mou shindeiru!
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(a) (a).begin(),(a).end()
#define fr(i,a,b) for (i = a; i <= b; i++)
#define frr(i,a,b) for (i = a; i >= b; i--)
#define rep(i,n) for (i = 0 ; i < n; i++)
#define repr(i,n) for (i = n - 1; i >= 0; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define flushinput   cin.ignore(numeric_limits<streamsize>::max(),'\n');

void debug_out() { cerr << endl; }

void clock_out(){
  cerr<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
}

void fileio(){
  freopen("/home/dwai/Desktop/cp/input.txt","r", stdin);
  freopen("/home/dwai/Desktop/cp/output.txt", "w", stdout);
  freopen("/home/dwai/Desktop/cp/debug.txt", "w", stderr);
}

void ofileio(){
  freopen("input.txt","r", stdin);
  freopen("output.txt", "w", stdout); 
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define fio() fileio()
#define ofio() fileio()
#define clock() clock_out()
#else
#define debug(...) 42
#define fio() 42
#define ofio() ofileio()
#define clock() 42
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef map<ll,ll> mll;

int IT_MAX = 1 << 20;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;


ll fast_exp(ll base, ll exp)
{
  if(base==0) return 0;
  ll res=1;
  while(exp>0)
  {
    if(exp&1)
      res=(res*base)%MOD;
    base=(base*base)%MOD;
    exp/=2;
  }
  return res%MOD;
}


void solve()
{
	ll n;cin>>n;
	ll dp[n]={0};
	ll i;
	ll a[n];
	mll m;
	rep(i,n){
		cin>>a[i];
		m[a[i]]++;
	}
	if(a[0]!=0)
	{
		cout<<0;
		return;
	}
	sort(a,a+n);
	for(auto x:m)
	{
		ll val=x.ff;
		ll freq=x.ss;
		if(val==0){
			if(freq>1) {
				cout<<0;
				return;
			}
			dp[0]=freq;
		}
		else dp[val]=(dp[val-1]*fast_exp(m[val-1],freq))%MOD;
	}
	cout<<(dp[a[n-1]]+MOD)%MOD;
}

int main()
{
//	fio();
	fast
	ll t=1;
	//cin>>t;

	while(t--){
		solve();	
	}
	return 0;
}