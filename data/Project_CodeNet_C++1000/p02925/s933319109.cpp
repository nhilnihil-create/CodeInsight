
// E - League

// 有向グラフを用いる解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int MAX_N = 1000;
const int MAX_V = MAX_N * (MAX_N - 1) / 2;

int players_to_game_idx[MAX_N][MAX_N];

struct Node {
	vector<int> next_nodes;
	bool visited = false;
	bool complete = false;
};

Node nodes[MAX_V];
int longest_path_length[MAX_V]; // nodes[i] からの最長パスの長さ
bool cycle = false;

int dfs(int idx) {
	if (nodes[idx].visited) {
		if (nodes[idx].complete) {
			return longest_path_length[idx];
		} else {
			cycle = true;
			return -1;
		}
	}

	nodes[idx].visited = true;

	for (int next_idx : nodes[idx].next_nodes) {
		longest_path_length[idx] = max(longest_path_length[idx], dfs(next_idx) + 1);
	}

	nodes[idx].complete = true;
	return longest_path_length[idx];
}



int main() {
	int N;
	cin >> N;

	int idx = 0;
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			players_to_game_idx[i][j] = idx;
			players_to_game_idx[j][i] = idx;
			idx++;
		}
	}

	int V = idx;

	int A, player1, player2;
	for (int i=0; i<N; i++) {
		cin >> A;
		A--;
		player1 = i;
		player2 = A;
		int from_idx = players_to_game_idx[player1][player2];

		for (int j=1; j<N-1; j++) {
			cin >> A;
			A--;
			player2 = A;
			int to_idx = players_to_game_idx[player1][player2];
			nodes[from_idx].next_nodes.push_back(to_idx);
			from_idx = to_idx;
		}
	}

	/*
	// **** debug ****
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			cout << i+1 << " " << j+1 << " -> " << players_to_game_idx[i][j] << endl;
		}
	}
	for (int i=0; i<V; i++) {
		for (int idx : nodes[i].next_nodes) {
			cout << i << "->" << idx << endl;
		}
	}
	*/


	for (int i=0; i<V; i++) {
		dfs(i);
	}

	if (cycle) {
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;
	for (int i=0; i<V; i++) {
		ans = max(ans, longest_path_length[i] + 1) ;
		//cout << "idx=" << i << " longest path=" << longest_path_length[i] + 1 << endl; // **** debug ****
	}
	cout << ans << endl;

	return 0;
}