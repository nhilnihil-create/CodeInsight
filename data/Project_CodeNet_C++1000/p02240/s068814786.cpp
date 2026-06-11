#include <stdio.h>
#include <vector>
#include <stack>
#define MAX 100010
#define INFTY 10000000
#define NIL -1

using namespace std;

int N;
int M;
vector<int> V[MAX];
int color[MAX];

int dfs(int s, int t)
{
	stack<int> S;
	S.push(s);
	color[s] = t;
	
	while (!S.empty()) {
		int u = S.top(); S.pop();
		for (int i=0; i<V[u].size(); i++) {
			int v = V[u][i];
			if (color[v] == NIL) {
				color[v] = t;
				S.push(v);
			}
		}
	}	
}

void assignColor()
{
	int id =1;
	for (int i=0; i<N; i++) {
		color[i] = NIL;
	}
	for (int u=0; u<N; u++) {
		if (color[u] == NIL) dfs(u, id++);
	}
}


int main()
{
	int i, n, u, v;	
	scanf("%d %d", &N, &M);	
	for (i = 0; i < M; i++) {
		scanf("%d %d", &n, &v);
		V[n].push_back(v);
		V[v].push_back(n);
	}
	
	assignColor();
	
	int Q;
	scanf("%d", &Q);
	for (i = 0; i < Q; i++) {
		scanf("%d %d", &u, &v);
		/*
		if (dfs(u, v) == 1) {
			puts("yes");
		}
		else {
			puts("no");
		}*/
		if (color[u] == color[v]) {
			puts("yes");			
		}
		else {
			puts("no");
		}
	}

	return 0;
}