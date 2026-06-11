#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
typedef long long  ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define fi first
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef pair<double, double>  iidb;
typedef pair<ll, ii>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9+7;
const double PI = acos(-1);
const ll MOD= 1e9+7;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 210000
#define offset 200
#define ptr nodo*
const ll inf=2e18;

const double EPS=1e-9;
ll dp[tam],v[tam];
int main()
{
	dp[0]=1000;
	int n;
	cin>>n;
	forr(i,1,n+1)
		cin>>v[i];
	forr(j,1,n+1)
	{

		forr(k,0,j)
		dp[j]=max(dp[j],dp[k]);
		forr(k,1,j)
		{
				dp[j]=max(ll(dp[k]/v[k])*v[j]+dp[k]%v[k],dp[j]);
		}
		//cout<<dp[j]<<" ";
	}
	cout<<dp[n]<<endl;
}				