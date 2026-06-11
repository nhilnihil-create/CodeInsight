#include <iostream>
using namespace std;
static const int Max = 100;
static const int Inf = 100000000; // ??????
static const int Nil = -1; // 

enum Status {
	Not_Searched = 0,
	Connected = 1,
	Searched = 2
};

int n;
int M[Max][Max] = {};
Status st[Max] = {}; 
int min_cost[Max] = {}; // min cost of point from start
//int parent[Max] = {}; // ??????index

void dijkstra() {
	for (int i = 0; i < n; i++) {
		min_cost[i] = Inf;
	}

	min_cost[0] = 0;
	st[0] = Connected;
	while (1) {
		int mincost = Inf;
		int min_index = Nil;
		for (int i = 0; i < n; i++) {
			if (st[i] != Searched && mincost > min_cost[i]) {
				mincost = min_cost[i];
				min_index = i;
			}
		}
		if (min_index == Nil) break;
		// index ?????????????????????????????????
		st[min_index] = Searched;
		for (int i = 0; i < n; i++) {
			// min_index ??¨???????????£??????????????????????????????????????????
			if (st[i] != Searched && M[min_index][i] != Inf) {
				if (min_cost[i] > min_cost[min_index] + M[min_index][i]) {
					min_cost[i] = min_cost[min_index] + M[min_index][i];
					st[i] = Connected;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i << " " << (min_cost[i] == Inf ? -1 : min_cost[i]) << endl;
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = Inf;
		}
	}
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int vi, ci;
			cin >> vi >> ci;
			M[i][vi] = ci;
		}
	}
	dijkstra();
	return 0;
}