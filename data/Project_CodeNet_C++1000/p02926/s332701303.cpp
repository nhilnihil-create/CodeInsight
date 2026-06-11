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
vector<pair<double,pair<double,double> > >datas;
pair<double,double> rui[200];
double calc(int lef,int rig){//添字lef~rigのベクトルの和
	double sumx,sumy;
	if(lef>rig){
		sumx=rui[rig+1].first+rui[N].first-rui[lef].first;
		sumy=rui[rig+1].second+rui[N].second-rui[lef].second;
	}else{
		sumx=rui[rig+1].first-rui[lef].first;
		sumy=rui[rig+1].second-rui[lef].second;
	}
	//cout<<lef<<" "<<rig<<" "<<sumx<<" "<<sumy<<" "<<sqrt(sumx*sumx+sumy*sumy)<<endl;
	return sqrt(sumx*sumx+sumy*sumy);
}
int main(){
	cin>>N;
	double nowx=0.0,nowy=0.0;
	rui[0]=mp(nowx,nowy);
	rep(i,N){
			
			double x,y;
			cin>>x>>y;
			double theta=atan2(y,x);
			//if(y<0)theta+=acos(-1.0);
			
			datas.pb(mp(theta,mp(x,y)));
			
	}
	sort(all(datas));
	rep(i,N){
		//cout<<datas[i].first<<" "<<datas[i].second.first<<" "<<datas[i].second.second<<endl;
		nowx+=datas[i].second.first;
		nowy+=datas[i].second.second;
		//cout<<nowx<<" "<<nowy<<endl;
		rui[i+1]=mp(nowx,nowy);

	}
	double ans=0.0;
	rep(lef,N)rep(rig,N){
		//計算
		//if(ans<calc(lef,rig))cout<<lef<<" "<<rig<<endl;
		ans=max(calc(lef,rig),ans);
	}
	printf("%.15lf\n",ans);
	
}
