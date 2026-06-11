#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

static const int MaxV = 10000;

vector<int> AdjL[MaxV];
int InDegree[MaxV];
queue<int> Q;

int main() {
	int V, E;
	int s, t;

	cin >> V >> E;
	for (int i = 0; i < V; i++) {
		InDegree[i] = 0;
	}
	for (int i = 0; i < E; i++) {
		cin >> s >> t;
		AdjL[s].push_back(t);
		InDegree[t]++;
	}
	for (int i = 0; i < V; i++) {
		if (InDegree[i] == 0) {
			Q.push(i);
		}
	}
	while (Q.empty() == false) {
		s = Q.front();
		Q.pop();
		cout << s << endl;
		for (unsigned int i = 0; i < AdjL[s].size(); i++) {
			t = AdjL[s][i];
			if (--InDegree[t] == 0) {
				Q.push(t);
			}
		}
	}

	return 0;
}