#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define cl(x,y) memset(x,y,sizeof(x))
#define ct cerr<<"Time elapsed:"<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lson x<<1,l,mid
#define rson x<<1|1,mid+1,r
#define INF 1e18
const int N=1e6+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1);
using namespace std;
int a[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k,i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(i=1;i<=n-k;i++)
		ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
