#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	std::vector<std::vector<int>> adj(N+1);

	int ai, bi;
	for (int i = 0; i < M; ++i) {
		cin >> ai >> bi;

		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}

	// for (int i = 1; i <= N; ++i) {
	// 	adj[i][i] = 1;
	// }

	// for(int i = 1; i <= N; ++i) {
	// 	for (int j = 1; j <= N; ++j)
	// 		cout << adj[i][j] << " ";
	// 	cout << endl;
	// }

	int res = 0;

	bool *visited = (bool*) malloc(sizeof(bool) * (N+1));
	memset(visited, false, N+1);

	// cout << "visited: ";
	// for(int i = 1; i <= N; ++i) {
	// 	cout << visited[i] << " ";
	// }
	// cout << endl;

	for(int i = 1; i <= N; ++i) {
		if (visited[i])
			continue;
		// cout << "visiting " << i << endl;
		std::stack<int> v;
		v.push(i);

		while(!v.empty()){

			int x = v.top();
			v.pop();

			visited[x] = true;
			// cout << "visited[" << x << "] = " << visited[x] << endl;

			for(auto ip = adj[x].begin(); ip != adj[x].end(); ++ip) {
				if(!visited[*ip])
					v.push(*ip);
			}
		}
		res += 1;
	}

	// cout << "After, visited: ";
	// for(int i = 1; i <= N; ++i) {
	// 	cout << visited[i] << " ";
	// }
	// cout << endl;

	cout << res - 1 << endl;

	return 0;
}