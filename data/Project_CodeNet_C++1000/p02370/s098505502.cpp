#include<iostream>
#include<list>
#include<queue>
#include<stdio.h>
using namespace std;
struct Node {
	//int id;
	int indegree;
	list<int> next;
};
Node graph[10002];
int visit[10002];
int n, m;
queue<int> answer;
void bfs(int beginNodeId) {
	queue<int> Q;
	Q.push(beginNodeId);
	while (!Q.empty()) {
		int id = Q.front(); Q.pop();
		visit[id] = 1;
		answer.push(id);

		list<int>::iterator it = graph[id].next.begin();
		for (it; it != graph[id].next.end(); it++) {
			int nextid = *it;
			graph[nextid].indegree--;
			if (graph[nextid].indegree == 0 && visit[nextid] == 0) {
				Q.push(nextid);
			}
		}
	}

}
void topologicalSort() {
	for (int i = 0; i < n; i++) {
		if (graph[i].indegree == 0 && visit[i]==0) {
			bfs(i);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		graph[a].next.push_back(b);
		graph[b].indegree++;
	}
	topologicalSort();
	while (!answer.empty()) {
		int ans = answer.front(); answer.pop();
		printf("%d\n",ans);
	}
}
