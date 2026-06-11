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
vi A;
ll results[314514];
map<int,int> cnt;
int cnt2[314514]={0};
int ans[314514];
int main(){
	cin>>N;
	rep(i,N){
		int x;
		cin>>x;
		A.pb(x);
		cnt[x]++;
	}
	for(auto i=cnt.begin();i!=cnt.end();++i){
		cnt2[i->second]++;
	}
	ll plus=(ll)0;
	rep(i,N+1){
		//cout<<cnt2[i]<<endl;
		//if(cnt2[i]>0)plus++;
		plus+=cnt2[i];
	}

	ll sum=0;
	results[0]=N+1;
	for(int i=1;i<=N;i++){
		sum+=plus;
		plus-=cnt2[i];
		results[i]=sum/i;
		//cout<<results[i]<<endl;
	}
	int aans=N;
	for(int i=1;i<=N;i++){
		while(results[aans]<i){
			aans--;
		}
		ans[i]=aans;
	}
	rep(i,N)cout<<ans[i+1]<<endl;

}
