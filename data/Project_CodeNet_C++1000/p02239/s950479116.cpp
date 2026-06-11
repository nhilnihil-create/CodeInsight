#include<iostream>
#include<queue>
using namespace std;

int n;;
int A[101][101];
int d[101];

void bfs(int r) {
	queue<int> Q;
	Q.push(r);
	d[r] = 0;
	while (!Q.empty()) {
		int t = Q.front();
		Q.pop();
		for (int i = 1; i <= n; i++) {
			if (A[t][i] && d[i] == -1) {
				d[i] = d[t] + 1;
				Q.push(i);
			}
		}
	}
}

int main() {
	int u, v, l;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		d[i] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> u >> l;
		for (int j = 0; j < l; j++) {
			cin >> v;
			A[u][v] = 1;
		}
	}

	bfs(1);

	for (int i = 1; i <= n; i++) {
		cout << i << ' ' << d[i] << endl;
	}
	
	return 0;
}