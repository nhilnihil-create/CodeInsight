
#include <iostream>
static const  int INFTY = 100000000;
static const  int WHITE =0;
static const  int GRAY= 10;
static const  int BLACK = 100;

using namespace std;

void  dijkstra(int n,int M[100][100]) {
	int color[100], d[100],p[100];
	for (int i = 0; i < n; i++) {
		color[i] = WHITE;
		d[i] = INFTY;
	}
	d[0] = 0;
	p[0] = -1;

	int u = -1;
	while (1) {
		int mincost = INFTY;
		for (int i = 0; i < n; i++) {
			if (d[i] < mincost &&color[i] != BLACK) {
				 u = i;
				 mincost = d[i];
			}
		}
		if (mincost == INFTY) break;
		color[u] = BLACK;

		for (int v = 0; v < n; v++) {
			if (color[v] != BLACK && M[u][v] != INFTY) {
				if (d[v] > d[u] + M[u][v]) {
					d[v] = d[u] + M[u][v];
					p[v] = u;
					color[v] = GRAY;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
	}
}


int main() {
	int  n,u, k, v,c;
	int M[100][100];
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = INFTY;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> u >> k;
		
		for (int j = 0; j < k; j++) {
			cin >> v >> c;;
			M[u][v] = c;
		}
	}

	dijkstra(n,M);
	return 0;
}