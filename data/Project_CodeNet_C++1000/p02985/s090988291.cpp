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
	int con;
	int clr;
}node_t;
vector<node_t> node;

queue<int> q;


int main(void) {
	int N, K;
	cin >> N >> K;
	
	node = vector<node_t>(N + 1);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		node[a].edge.push_back(b);
		node[b].edge.push_back(a);
	}

	vector<bool> visit(N + 1);
	q.push(1);
	visit[1] = true;
	node[1].clr = K;
	ll ans = K;
	bool flag = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();	
		for (auto to : node[x].edge) {
			if (visit[to]) continue;
			visit[to] = true;
			node[to].clr = K - 1 - node[x].con;
			if (node[to].clr <= 0) {
				flag = false;
				break;
			}
			ans *= node[to].clr;
			ans %= DIV;
			node[x].con++;
			node[to].con++;
			q.push(to);
		}
		if (!flag) {
			break;
		}

	}

	if (flag)
		cout << ans << endl;
	else
		cout << 0 << endl;

}
