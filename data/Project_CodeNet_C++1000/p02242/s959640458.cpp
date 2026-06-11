#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
const int INF = 2000000000;
const int num = 100;
int n, u, k, v, w;
int m[num][num];
int d[num];
int c[num];
int main() {
	cin >> n;
	fill(m[0], m[num], INF);
	for (int i = 0; i < n; i++) {
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			cin >> v >> w;
			m[u][v] = w;
		}
	}
	fill(d, d + num, INF);
	fill(c, c + num, 0);
	d[0] = 0;
	while (true) {
		int ne = -1;
		int minv = INF;
		for (int i = 0; i < n; i++)
			if (!c[i] && d[i] < minv) {
				ne = i;
				minv = d[i];
			}
		if (ne == -1) break;
		c[ne] = 1;
		for (int i = 0; i < n; i++) {
			if (d[i] > d[ne] + m[ne][i]) d[i] = d[ne] + m[ne][i];
		}
	}
	for (int i = 0; i < n; i++)
		cout << i << " "<< d[i] << endl;
	return 0;
}