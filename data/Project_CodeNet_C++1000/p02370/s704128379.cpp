#include<stdio.h>
#include<vector>
using namespace std;

const int V_MAX = 10000;

int main() {
	int v, e;
	int table[V_MAX] = { 0 };
	vector<int> edge[V_MAX];
	vector<int> ans;

	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		edge[s].push_back(t);
		table[t]++;
	}
	
	for (int i = 0; i < v; i++) {
		if (table[i] == 0) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < ans.size();i++) {
		vector<int> e = edge[ans[i]];
		for (int j = 0; j < e.size(); j++) {
			if (--(table[e[j]]) == 0) {
				ans.push_back(e[j]);
			}
		}
	}

	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
		printf("%d\n", *it);
	}
	
	return 0;
}