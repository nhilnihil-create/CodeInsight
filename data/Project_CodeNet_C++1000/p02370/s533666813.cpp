#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
using namespace std;
const int num = 10000;
vector<int> ne[num];
int n, c[num];
list<int> ans;
inline void dfs(int a) {
	c[a] = 1;
	for (int i = 0; i < ne[a].size(); i++)
		if (c[ne[a][i]] == 0) dfs(ne[a][i]);
	ans.push_front(a);
}
inline void tp() {
	for (int i = 0; i < n; i++) 
		if (c[i] == 0) dfs(i);
}
int main() {
	int p, s, t;
	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		scanf("%d%d", &s, &t);
		ne[s].push_back(t);
	}
	for (int i = 0; i < n; i++) c[i] = 0;
	tp();
	for (int i = 0; i < n; i++) {
		list<int>::iterator it  = ans.begin();
		printf("%d\n", *it);
		ans.pop_front();
	}
	return 0;
}