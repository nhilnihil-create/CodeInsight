
// E - Hopscotch Addict

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

using Idx = int;
using Step = int;

struct Node {
	vector<int> neighbors;
	bool visited[3];

	Node() {
		visited[0] = false;
		visited[1] = false;
		visited[2] = false;
	}
};

int N, M, S, T;
Node nodes[100000];

int bfs(int start, int goal) {
	nodes[start].visited[0] = true;

	queue<pair<Idx, Step>> search_queue;
	search_queue.push(make_pair(start, 0));

	while(!search_queue.empty()) {
		pair<Idx, Step> current = search_queue.front();
		search_queue.pop();

		int idx = current.first;
		int step = current.second;
		//cout << idx + 1 << " (" << step << ")" << endl; // **** debug ****

		if (idx == T && step % 3 == 0) {
			return step / 3;
		}

		int next_r = (step + 1) % 3;
		for (int next_idx : nodes[idx].neighbors) {
			if (nodes[next_idx].visited[next_r]) {
				continue; // 探索済みならキューに入れない
			}

			nodes[next_idx].visited[next_r] = true;
			search_queue.push(make_pair(next_idx, step + 1));
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;

	int u, v;
	for (int i=0; i<M; i++) {
		cin >> u >> v;
		u--;
		v--;
		nodes[u].neighbors.push_back(v);
	}

	cin >> S >> T;
	S--;
	T--;

	int ans = bfs(S, T);

	cout << ans << endl;

	return 0;
}