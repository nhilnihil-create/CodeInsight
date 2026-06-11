#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<functional>
#include<set>
#include<unordered_map>
using namespace std;

vector<int>c[10000];
bool used[10000];
vector<int>V;
void DFS(int a) {
	used[a] = true;
	for (int i : c[a]) {
		if (!used[i])DFS(i);
	}
	V.push_back(a);
}
signed main() {
	int a, b; scanf("%d%d", &a, &b);
	for (int d = 0; d < b; d++) {
		int e, f; scanf("%d%d", &e, &f);
		c[f].push_back(e);
	}
	for (int i = 0; i < a; i++) {
		if (!used[i])DFS(i);
	}
	for (int i : V) {
		cout << i << endl;
	}
}