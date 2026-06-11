#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846264338327950L

//ダイクストラ高速版

struct edge { int src, dest, cost; };
using P = pair<int, int>; //距離、ノード番号

const int INF = INT_MAX;
int V;                      //Node数
map<int, vector<edge>> G; //edge集合、G[src][index]
// map<int, int> DIST;         //現状のコスト　DIST[Node][Cost]
vector< vector<int> > DIST;  //現状のコスト　DIST[Src][Dist]->[Cost]
map<int, int> preNode;      //最短経路上の1ホップ前のノード 




void init() {

	vector<int> vec(V, INF);
	for (int i = 0; i < V; i++) {
		DIST.push_back(vec);
	}

}

void setEdge(int src, int dest, int cost) {
	edge e = { src,dest,cost };
	G[src].push_back(e);
}

void dijkstra(int s) {
	//要素の型,内部コンテナの型、並べ替え方法
	//P->first＝距離で昇順にソート
	priority_queue<P, vector<P>, greater<P> > que;

	DIST[s][s] = 0;
	preNode[s] = s;
	que.push(P(0, s));

	while (!que.empty()) {

		P p = que.top(); que.pop();

		int tmp_node = p.second;
		if (DIST[s][tmp_node] < p.first) { continue; }
		for (auto g : G[tmp_node]) {
			edge e = g;
			if (DIST[s][e.dest] > DIST[s][tmp_node] + e.cost) {
				DIST[s][e.dest] = DIST[s][tmp_node] + e.cost;
				que.push(P(DIST[s][e.dest], e.dest));
				preNode[e.dest] = tmp_node;
			}
		}
	}


}


int main(void) {
	long long N, X, Y;
	map<long long, long long> ans;

	cin >> N >> X >> Y;


	V = N;//頂点数を登録

	//初期化
	init();

	//エッジの作成
	for (int i = 0; i < N-1; i++) {
		setEdge(i, i + 1, 1);
		setEdge(i + 1, i, 1);
	}
	setEdge(X - 1, Y - 1, 1);
	setEdge(Y - 1, X - 1, 1);

	for (long long i = 0; i < N; i++) {
		dijkstra(i);
	}

	for (long long i = 0; i < N; i++) {
		for (long long j = i; j < N; j++) {
			ans[DIST[i][j]]++;
		}
	}

	for (long long i = 1; i <= N - 1; i++) {
		cout << ans[i] << endl;
	}




	return 0;
}

