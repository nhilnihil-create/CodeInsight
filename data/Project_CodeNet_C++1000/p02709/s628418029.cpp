#include<bits/stdc++.h>
using namespace std;
 
#define     inf                 LONG_LONG_MIN
#define     INF                 LONG_LONG_MAX

#define     forn(i,ii,n)        for(int i=ii; i<=n; ++i)
#define     ford(i,n,ii)        for(int i=n; i>=ii; --i)
#define     pb                  push_back
#define     eb                  emplace_back
#define     sz(xx)              (int) xx.size()
#define     mk                  make_pair
#define     mem(x,v)            memset(x,v,sizeof x)
#define		clr(xx)				xx.clear()
#define		ff 					first
#define		ss 					second
#define		all(x)				x.begin(),x.end()
#define		nl 					cout << endl
#define     kase(x)             cout << "Case " << x <<": "
#define     fastt               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     dbg(args...)        do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
 
template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}

/*typedef*/
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ull> vul;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef priority_queue <pii, vector<pii>, greater<pii> > pq;	///for djkstra
/*typedef ends*/

const int maxn=2005;
int n;
pii a[maxn];
ll dp[maxn][maxn];
ll DP(int id, int left, int right)
{
    if(id>=n) return 0;
    ll &ret = dp[id][left];
    if(ret != -1) return ret;
    ll x = a[id].ff;
    int pos = a[id].ss;
    ret = max(x*(abs(pos-left))+DP(id+1,left+1,right),x*abs(pos-right)+DP(id+1,left,right-1));
    // dbg(ret);
    return ret;
}

int main()
{
    //  freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);

    fastt;
    cin>>n;
    forn(i,0,n-1) cin>>a[i].ff, a[i].ss=i;
    sort(a,a+n,[&](const pii& x, const pii& y){return (x.ff==y.ff) ? x.ss<y.ss : x.ff>y.ff;});
    mem(dp,-1);
    cout << DP(0,0,n-1);

	return 0;
}