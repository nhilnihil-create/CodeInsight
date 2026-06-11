#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define N 10001
using namespace std;
int main() {
	int V, E;
	scanf("%d %d", &V, &E);

	int s, t, L[N];
	vector <int> M[N];
	queue <int> S;

	for (int i = 0; i < N; i++) {
		L[i] = 0;
	}

	for (int i = 0; i < E; i++) {
		scanf("%d %d", &s, &t);
		M[s].push_back(t); 
		L[t]++; //tの持つ入力辺の数
	}

	for (int i = 0; i < V; i++) {
		if (L[i] == 0) {
			S.push(i); //入力辺を持たないノード
		}
	}

	int q;
	while (!S.empty()) {
		q = S.front();
		S.pop();
		printf("%d\n", q);
		for (int i = 0; i < M[q].size(); i++) {
			L[M[q][i]]--; //辺を消す
			if (L[M[q][i]] == 0) { //もし入力辺を持っていないならば
				S.push(M[q][i]);
			}
		}
	}
	return 0;
}
