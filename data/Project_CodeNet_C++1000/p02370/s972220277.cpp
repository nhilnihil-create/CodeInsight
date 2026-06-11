#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;

typedef long long ll;

bool debug = false;
const int NIL = -1;
const ll INF = 400000000000;
const int NUM = 10010;
clock_t START, END;

queue<int> Q;
list<int> out;
vector<int> G[NUM];
int indeg[NUM], cor[NUM];
int V;

void bfs(int s)
{
	int u;
	Q.push(s);
	cor[s] = 1;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		out.push_back(u);
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indeg[v]--;
			if (indeg[v] == 0 && cor[v] == 0) {
				cor[v] = 1;
				Q.push(v);
			}
		}
	}
}

int main(void)
{
	if (debug) {
		START = clock();
		freopen("in44.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int E, s, t;
	bool negative = false;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> s >> t;
		G[s].push_back(t);
		indeg[t]++;
	}
	for (int i = 0; i < V; i++) {
		if (indeg[i] == 0 && cor[i] == 0)
			bfs(i);
	}
	for (list<int>::iterator it = out.begin(); it != out.end(); it++)
		cout << *it << endl;
	if (debug) {
		END = clock();
		double endtime = (double)(END - START) / 1000;
		printf("total time = %lf s", endtime);
	}
	return 0;
}
