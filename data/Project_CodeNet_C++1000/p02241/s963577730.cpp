#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
//#include "MyMath.h"
//#include "MyDisjointset.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <stdio.h>
using namespace std;
typedef pair<int, int> P;
const int INF = 2000000000;
int main() {
	int n; cin >> n;
	int m[101][101];
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
		cin >> m[i][j];
	int res = 0;
	int *d = new int[n];
	fill(d, d + n, INF); 
	d[0] = 0;
	bool *visit = new bool [n];
	fill(visit, visit + n, false);
	priority_queue <P, vector<P>, greater<P> > q;
	q.push(P(d[0], 0));
	while (!q.empty()) {
		int f = q.top().first, s = q.top().second;
		q.pop();
		if (visit[s]) continue;
		visit[s] = true;
		res += f;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				if (m[s][i] != -1) {
					if (m[s][i] < d[i]) {
						d[i] = m[s][i];
						q.push(P(d[i], i));
					}
				}
				}
			}
		}
	cout << res << endl;
	delete[] d, visit;
	return 0;
}