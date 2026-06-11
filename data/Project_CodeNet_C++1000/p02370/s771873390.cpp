#include<iostream>
#include<algorithm>
#include<vector>
#define MAXV 10001
#define MAXE 100001
using namespace std;

int main() {
	int i, j, v, e, s, t, isVisited[MAXV] = {};
	vector<int*> ntopa[MAXV];
	vector<int*>::iterator itv;


	cin >> v >> e;
	for (i = 0; i < e; i++) {
		cin >> s >> t;
		ntopa[t].push_back(&isVisited[s]);
	}

	i = -1;
	while (1) {
		++i %= v;
		if (isVisited[i])continue;
		for (itv = ntopa[i].begin(); itv != ntopa[i].end(); itv++) {
			if (*(*itv) == 0)break;
		}
		if (itv == ntopa[i].end()) {
			isVisited[i] = 1;
			cout << i << endl;
			i = 0;
			for (j = 0; j < v; j++) {
				if (isVisited[j] == 0)break;
			}
			if (j == v) return 0;
		}
	}


	return 0;
}