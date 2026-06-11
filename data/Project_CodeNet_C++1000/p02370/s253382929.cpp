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
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define MAX 10010
vvi G(MAX);
vi out;
bool V[MAX];
int n;
int indeg[MAX];
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
	out=vi(0);
	rep(i,n)indeg[i]=0;
	rep(i,n)rep(j,G[i].size()){
		int v=G[i][j];
		indeg[v]++;
	}
	rep(i,n)if(indeg[i]==0&&!V[i])bfs(i);
	rep(i,n)cout<<out[i]<<endl;
}
int main(){
	int s,t,m;
	cin>>n>>m;
	rep(i,n)V[i]=false;
	while(m--){
		cin>>s>>t;
		G[s].pb(t);
	}
	tsort();
}