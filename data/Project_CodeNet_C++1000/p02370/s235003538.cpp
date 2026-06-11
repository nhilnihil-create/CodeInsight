#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

vector<int>E[10000];
int in[10000];
bool used[10000];
int main() {
	int v, e; scanf("%d%d", &v, &e);
	rep(i, e) {
		int s, t; scanf("%d%d", &s, &t);
		E[s].push_back(t);
		in[t]++;
	}
	list<int>ls;
	queue<int>que;
	rep(i, v) {
		if (!used[i] && !in[i])que.push(i);
		while (!que.empty()) {
			int p = que.front(); que.pop();
			used[p] = true; ls.push_back(p);
			for (int u : E[p]) {
				in[u]--;
				if (!used[u] && !in[u])que.push(u);
			}
		}
	}
	for (int i : ls) {
		printf("%d\n", i);
	}
}