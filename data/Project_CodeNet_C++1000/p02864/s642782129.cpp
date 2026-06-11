#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define ktya(x) sort(all(x))
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 1e18
#define INFLL 1000000000000000007LL
#define SIZE 200105
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define PI (acos(-1))
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
typedef pair<pill,int> PA;
//ll MOD;
ll MOD = 1000000007;
// ll MOD=998244353;
typedef ll Weight;
struct Edge {
	int src, dst;
	ll weight;
};
int N;
int K;
ll H[500];
ll dp[500][500]={0};
vector<ll> rireki;
int main(){
	cin>>N>>K;
	ll ans=3e12;
	H[0]=(ll)0;
	rep(i,N){
		cin>>H[i+1];
	}
	rep(i,N+1)rep(j,N+1)dp[i][j]=3e12;
	dp[0][0]=(ll)0;
	rep(i,N+1)dp[i][1]=H[i];
	for(int i=1;i<=N;i++)for(int j=2;j<=N;j++){
	
			for(int k=1;k<i;k++){
				if(k>1)dp[i][j]=min(dp[i][j],dp[k][j-1]+max((ll)0,H[i]-H[k]));
				else dp[i][j]=dp[k][j-1]+max((ll)0,H[i]-H[k]);
			}

	}
	/*rep(i,N){
		rep(j,N){
			ll x=dp[i+1][j+1];
			if(x>=3e12)cout<<"inf";
			else cout<<dp[i+1][j+1];
		}
		cout<<endl;
	}*/
	rep(i,N)ans=min(ans,dp[i+1][N-K]);
	if(N==K)ans=0;
	cout<<ans<<endl;

}
