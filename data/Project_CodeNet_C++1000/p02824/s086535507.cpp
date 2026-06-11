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
#define all(aa) (aa).begin(), (aa).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 1e18
#define INFLL 1000000000000000007LL
#define SIZE 200105
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define PI (acos(-1))
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
typedef pair<pair<ll, ll>,int> PP;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
typedef pair<pill,int> PA;
//ll MOD;
ll MOD = 1000000007;
//ll MOD=998244353;
typedef ll Weight;
struct Edge {
	int src, dst;
	ll weight;
};

int use[55]={0};
int N,V,Pr;
ll M;
ll A[114514];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N;
	cin>>M;
	cin>>V>>Pr;
	rep(i,N){
		cin>>A[i];
	}
	sort(A,A+N);
	reverse(A,A+N);
	/*rep(i,N)cout<<A[i]<<" ";
	cout<<endl;*/
	int ok=Pr-1,ng=N+1;//1-index
	while(ng-ok>1){
		int mid=(ng+ok)/2;
		//midで行けるかどうか
		int cnt=V-(Pr+N-mid);
		if(A[Pr-1]>A[mid-1]+M){
			ng=mid;
		}else if(cnt<=0){
			ok=mid;
		}else{
			//cnt問に+1　をM回繰り返してすべてA[mid-1]+M以下にできるかどうかチェック
			//A[mid-1]+M-A[i-1]<=Mに注意すると和だけ見ればよい。
			ll line=A[mid-1]+M;
			ll sum=0;
			bool flag=true;
			for(int i=Pr;i<=mid-1;i++){
				sum+=line-A[i-1];
				if(line-A[i-1]<0)flag=false;
			}
			//cout<<sum<<" "<<cnt<<" "<<M<<endl;
			if(flag){
				if(sum>=cnt*M)ok=mid;
				else ng=mid;
			}else{
				ng=mid;
			}
		}
	}
	
	cout<<ok<<endl;
}