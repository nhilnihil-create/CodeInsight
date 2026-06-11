#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define ld long double
#define pii pair <int,int>
#define pll pair <ll,ll>
#define pil pair <int,ll>
#define pli pair <ll,int>
#define ull unsigned long long
#define pdd pair <double,double>
#define pb push_back
#define mp make_pair
#define puu pair<ull,ull>
#define pvv pair<vector<int>, vector<int> >
#define _bp __builtin_popcount
#define ptt pair <Tree*,Tree*>
#define all(v) v.begin(),v.end()
#define en "\n"
//const long double pi = acos(-1);
void boos()
{
     ios_base :: sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
}
void file()
{
   freopen("robot.in","r",stdin);
   freopen("robot.out","w",stdout);
}
const ll INF = (ll)1e9 + 7ll;
const ll INF1 = 998244353;
const ll LLINF = (ll)1e18;
const ll INTmx = (int)1e9;
const ld EPS = (ld)1e-9;
const int N = 2e3 + 100;
ll dp[N][N];
bool u[N][N];
pll a[N];
void calc(int l,int r)
{
	pll mx = a[r - l + 1];
	u[l][r] = 1;
	if(l == r)
	{
		dp[l][r] = mx.f * abs(mx.s - l);
		return;
	}
	if(!u[l + 1][r])
	{
		calc(l + 1,r);
	}
	if(!u[l][r - 1])
	{
		calc(l,r - 1);
	}
	ll ans = 0;
	ll dd = mx.f * abs((mx.s - l));
	ll tt = mx.f * abs((mx.s - r));
	ans = max(ans,dp[l + 1][r] + dd);
	ans = max(ans,dp[l][r - 1] + tt);
	dp[l][r] = ans;
}
int main()
{
    //file();
    boos();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i].f;
    	a[i].s = i;
	}
	sort(a + 1,a + n + 1);
	calc(1,n);
	cout << dp[1][n];
}