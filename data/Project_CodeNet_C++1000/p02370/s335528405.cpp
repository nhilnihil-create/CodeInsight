#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

static const int MAX = 10000;

static const bool DEBUG = false;

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	V[s] = true;
	//DEBUG
	if (DEBUG == true) {
		cout << "in BFS 1" << endl;
		cout << "V[i]:" << endl;
		for (int i = 0; i < N; i++) {
			cout << V[i] << " ";
		}
		cout << endl;

		cout << "indeg[i]:" << endl;
		for (int i = 0; i < N; i++) {
			cout << indeg[i] << " ";
		}
		cout << endl;
	}

	while (!q.empty()) {
		int u = q.front(); q.pop();
		out.push_back(u);
		for (unsigned int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indeg[v]--;
			//if (indeg[v] == 0 && !V[v]) {
			if (indeg[v] == 0) {
				V[v] = true;
				q.push(v);
				if (DEBUG == true) {
					//DEBUG
					cout << "in BFS 2" << endl;
					cout << "V[i]:" << endl;
					for (int i = 0; i < N; i++) {
						cout << V[i] << " ";
					}
					cout << endl;

					cout << "indeg[i]:" << endl;
					for (int i = 0; i < N; i++) {
						cout << indeg[i] << " ";
					}
					cout << endl;
				}
			}

		}
	}
}

void tsort() {
	for (int i = 0; i < N; i++) {
		indeg[i] = 0;
	}

	for (int u = 0; u < N; u++) {
		for (unsigned int i = 0; i < G[u].size(); i++) {
			int v = G[u][i];
			indeg[v]++;
		}
	}

	if (DEBUG == true) {
		//DEBUG
		cout << "V[i]: ";
		for (int i = 0; i < N; i++) {
			cout << V[i] << " ";
		}
		cout << endl;

		cout << "indeg[i]: ";
		for (int i = 0; i < N; i++) {
			cout << indeg[i] << " ";
		}
		cout << endl;
	}


	for (int u = 0; u < N; u++) {
		if (indeg[u] == 0 && !V[u]) {
			bfs(u);
		}
	}

	for (list<int>::iterator it = out.begin(); it != out.end(); it++) {
		cout << *it << endl;
	}
}

int main() {
	int s, t, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) V[i] = false;

	for (int i = 0; i < M; i++) {
		cin >> s >> t;
		G[s].push_back(t);
	}

	tsort();

	return 0;
}