#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#define MAX_V 10
#define INF 1000000
#define NIL -1
using namespace std;

struct edge {int to,cost;};
typedef pair<int,int> P;	//first:最短距離 second:頂点番号


int d[MAX_V];

void dijkstra(int s,vector<edge> G[]){
	//greater<P>を指定することでfirstが小さい順に取り出せるようになる
	priority_queue<P,vector<P>,greater<P> > que;
	d[s] = 0;
	que.push(P(0,s));

	while(!que.empty()){
		P p = que.top();que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;//最短距離でなければ無視する
		for(int i = 0;i < G[v].size();i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
	
}

int E;
bool cities[MAX_V];//その番号の町が出てくるか否か

int main(){
	cin >>E;
	while(E != 0){
		vector<edge> G[MAX_V];		//隣接リスト
		fill(cities,cities + MAX_V,false);
		int a,b,cost;
		for(int i = 0;i < E;i++){
			cin >>a >>b >>cost;
			cities[a] = true;cities[b] = true;
			edge e;e.to = b;e.cost = cost;
			G[a].push_back(e);
			e.to = a;
			G[b].push_back(e);
		}
		int mini = INF;int num = NIL;
		for(int i = 0;i < MAX_V;i++){
			fill(d,d+MAX_V,INF);
			for(int j = 0;j < MAX_V;j++){
				if(!cities[j])d[j] = 0;}
			dijkstra(i,G);
			int min_tmp= 0;
			for(int k = 0;k < MAX_V;k++)min_tmp += d[k];
			if(min_tmp < mini){mini = min_tmp;num = i;}
		}
		cout <<num <<" " <<mini <<endl;
		cin >>E;
	}
	return 0;
}