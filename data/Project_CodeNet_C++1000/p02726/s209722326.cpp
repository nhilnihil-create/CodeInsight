#define _DEBUG
#include "bits/stdc++.h"
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif
#define rep(index,num) for(int index=0;index<(int)num;index++)
#define rep1(index,num) for(int index=1;index<=(int)num;index++)
#define brep(index,num) for(int index=(int)num-1;index>=0;index--)
#define brep1(index,num) for(int index=(int)num;index>0;index--)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=(ll)1e+18+1;
int INF=1e+9+1;
vpint adj[10000];
int d[10000],color[10000],p[10000];
void dijkstra(int N,int st){
	priority_queue<pint> PQ;//辺の長さのオーバーフローに注意！
	rep(i,N){
		d[i]=INF;
		color[i]=0;
	}
	d[st]=0;
	color[st]=1;
	PQ.push(mp(0,st));
	while(!PQ.empty()){
		pint f=PQ.top();
		PQ.pop();
		int u=f.second;
		color[u]=2;
		if(d[u]< -f.first) continue;
		rep(j,adj[u].size()){
			int v=adj[u][j].first;
			if(color[v]==2) continue;
			if(d[v]>d[u]+adj[u][j].second){
				d[v]=d[u]+adj[u][j].second;
				PQ.push(mp(-d[v],v));
				color[v]=1;
			}
		}
	}
}
int main(){
	int N,X,Y;
	scan(N>>X>>Y);
	X--; Y--;
	rep(i,N-1){
		adj[i].push_back({i+1,1});
		adj[i+1].push_back({i,1});
	}
	adj[X].push_back({Y,1});
	adj[Y].push_back({X,1});
	int cnt[N]={};
	rep(i,N){
		dijkstra(N,i);
		rep(j,N){
			cnt[d[j]]++;
		}
	}
	rep1(k,N-1){
		prin(cnt[k]/2);
	}
	return 0;
}
