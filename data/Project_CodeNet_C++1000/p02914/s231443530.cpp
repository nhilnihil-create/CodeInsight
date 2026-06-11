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
int nums[114514][65]={0};
int hoge[65]={0};
int main(){
	cin>>N;
	vector<ll> A(N);
	ll sum=0;
	rep(i,N){
		cin>>A[i];
		sum^=A[i];
		ll temp=A[i];
		rep(j,65){
			nums[i][j]=temp%2;
			temp/=2;
		}
	}
	rep(i,N)A[i] &= ~sum;
	ll ans=0;
	ll now=1;
	rep(i,61){
		if(sum%2==0)hoge[i]=11;
		else ans+=now;
		now*=2;
		sum/=2;
	}
	ll X=0;
	int i,j;
	int rank=0;
	for (i = 59; i >= 0; i--) {
		for (j = rank; j < N; j++) {
			if (A[j] & (1LL << i)) break;
		}
		if (j == N) {
			continue;
		}
 
		if (j > rank) A[rank] ^= A[j];
		for (j = rank + 1; j < N; j++) {
			A[j] = min(A[j], A[j] ^ A[rank]);
		}
 
		rank++;
	}
	rep(i,N)X=max(X,X^A[i]);
	cout<<2*X+ans<<endl;
}
