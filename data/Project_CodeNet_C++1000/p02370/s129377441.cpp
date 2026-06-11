// topological sort (breadth first search)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>

const int N = 10010;
const int M = 100010;

struct Edge {
	int to, next;
} es[M];

int SIZE = 0; // number of edges
int h[N]; // pointer to edge list
int in[N], queue[N]; // in-degree, queue for BFS

inline void add(int u, int v) {
	int i = ++SIZE;
	es[i].to = v;
	es[i].next = h[u];
	h[u] = i; 
}

void run() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	memset(h, 0, sizeof(h));
	memset(in, 0, sizeof(in));
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		in[y] += 1;
	}
	int front = 0, back = 0;
	for (int i = 0; i < n; i++)
		if (in[i] == 0)
			queue[back++] = i;
	while (front < back) {
		int x = queue[front++];
		for (int i = h[x]; i != 0; i = es[i].next) {
			int y = es[i].to;
			in[y] -= 1;
			if (in[y] == 0)
				queue[back++] = y;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", queue[i]);
}

int main() {
	run();
}