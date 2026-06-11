#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<functional>
#include<algorithm>
#include<stack>
#include<queue>
#include<iomanip>
#include<set>
#include<map>
#include<utility>
#include<string>
#include<vector>

using namespace std;

#define LL long long
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
bool OOA(int x,int y,int H,int W){return (0<=x&&x<H)&&(0<=y&&y<W);}

struct Graph {
	int V, E, t;
	//vector<int>cost;
	vector<int>gr;
	//vector<bool>vzt;
	vector<vector<int>>adj;
	void init(int dflt) {//dflt!=0
		adj = vector<vector<int>>(V + 1);
	//	cost = vector<int>(V + 1, dflt);
		gr = vector<int>(V + 1, dflt);
	//	vzt = vector<bool>(V + 1, false);
	}

	void dfs(int now) {
		if (gr[now] == -1) { gr[now] = t; }
		else return;
		for (int i = 0;i<adj[now].size();i++)dfs(adj[now][i]);
		return;
	}

	void CC(){
		for(int i=0;i<V;i++){
			if(gr[i]==-1){
				t=i;
				dfs(i);
			}
		}
		return;
	}
};

Graph G;
int n,m,q;

int main() {
	cin>>n>>m;
	G.V=n;
	G.init(-1);
	for(int i=0;i<m;i++){
		int s,t;
		cin>>s>>t;
		G.adj[s].push_back(t);
		G.adj[t].push_back(s);
	}
	G.CC();
	cin>>q;
	for(int i=0;i<q;i++){
		int s,t;
		cin>>s>>t;
		cout<<(G.gr[s]==G.gr[t]?"yes":"no")<<endl;
	}
	return 0;
}
