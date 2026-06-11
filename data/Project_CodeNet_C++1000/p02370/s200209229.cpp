#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
class TOPO{//out is tsort's return.
	public:
	vvi G;
	vi out;
	vector<bool>V;
	vi indeg;
	int n;
	TOPO(int size){
		n=size;
		G=vvi(n);
		out=vi(0);
		V=vector<bool>(n);
		indeg=vi(n);
	}
	void add_edge(int s,int t){
		G[s].pb(t);
	}
	void bfs(int s){
		queue<int>q;
		q.push(s);
		V[s]=true;
		while(!q.empty()){
			int u=q.front();q.pop();
			out.pb(u);
			rep(i,G[u].size()){
				int v=G[u][i];
				indeg[v]--;
				if(indeg[v]==0&&!V[v]){
					V[v]=true;
					q.push(v);
				}
			}
		}
	}
	void tsort(){
		rep(i,n)indeg[i]=0;
		rep(i,n)rep(j,G[i].size()){
			int v=G[i][j];
			indeg[v]++;
		}
		rep(i,n)if(indeg[i]==0&&!V[i])bfs(i);
//		rep(i,n)cout<<out[i]<<endl;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	TOPO topo(n);
	while(m--){
		int a,b;
		cin>>a>>b;
		topo.add_edge(a,b);
	}
	topo.tsort();
	rep(i,n)cout<<topo.out[i]<<endl;
}