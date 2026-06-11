#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

typedef struct {
	vector<int> edge;
	ll dis = 1e10;
}node_t;
vector<node_t> node;

int main(void) {
	int N, M;
	cin >> N >> M;
	
	node = vector<node_t>(3*N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		node[a].edge.push_back(b+N);
		node[a+N].edge.push_back(b+2*N);
		node[a + 2 * N].edge.push_back(b);
	}

	int S, T;
	cin >> S >> T;

	queue<int> q;

	vector<bool> visit(3*N + 1);
	q.push(S);
	visit[S] = true;
	node[S].dis = 0;
	ll cnt = 0;
	while (!q.empty()&&cnt<=1e7) {
		int x = q.front();
		q.pop();	
		for (auto to : node[x].edge) {
			if (visit[to]) continue;
			visit[to] = true;
			q.push(to);
			node[to].dis = node[x].dis + 1;
			cnt++;
		}
	}

	if (node[T].dis == 1e10)
		cout << -1 << endl;
	else
		cout << node[T].dis/3 << endl;

}
