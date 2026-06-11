#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define N 100005
using namespace std;

int n, m, s, t, d[N][3];
vector<int> gr[N];
queue<pair<int,int>> qu;

int main() {
	int i, t1, t2, u, c;
	cin >> n >> m;
	while(m--) {
		scanf("%d%d", &t1, &t2);
		gr[t1].push_back(t2);
	}
	memset(d, 0x7f, sizeof(d));
	cin >> s >> t;
	qu.push({s, 0});
	d[s][0] = 0;
	while(!qu.empty()) {
		u = qu.front().first;
		c = qu.front().second;
		qu.pop();
		for(int v:gr[u]) {
			if(d[u][c] + 1 < d[v][(c+1)%3]) {
				d[v][(c+1)%3] = d[u][c] + 1;
				qu.push({v, (c+1)%3});
			}
		}
	}
	cout << (d[t][0]%3 ? -1 : d[t][0]/3);
	return 0;
}