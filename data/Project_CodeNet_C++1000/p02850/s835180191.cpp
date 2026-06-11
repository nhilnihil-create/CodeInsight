#include <bits/stdc++.h>
using namespace std;

class node {
   public:
	int k;
	int parents_node;
	int parents_color;
};
stack<class node> st;

void paint_node(int k, int parents_node, int parents_color,
                vector<vector<pair<int, int>>> *edge, vector<int> *c) {
	// std::cout << k << "\n";
	st.pop();
	int color = 0;
	for (auto a : (*edge)[k]) {
		// cout << "for " << k + 1 << ": " << a.first + 1 << " ";
		if (a.first == parents_node) {
			// cout << "is parent\n";
			continue;
		}
		if (color == parents_color) {
			color++;
		}
		(*c)[a.second] = color;
		// cout << "connect color is " << color + 1 << "\n";
		// cout << "c[" << a.second + 1 << "] is " << color + 1 << "\n";

		// paint_node(a.first, k, color, edge, c);

		class node next_node;
		next_node.k = a.first;
		next_node.parents_node = k;
		next_node.parents_color = color;
		st.push(next_node);
		color++;
	}
	return;
}

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N;
	scanf("%d", &N);

	vector<vector<pair<int, int>>> edge(N, vector<pair<int, int>>());
	vector<int> a(N), b(N), c(N, -1);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		// cout << a[i] + 1 << " " << b[i] + 1 << "\n";
		edge[a[i]].insert(edge[a[i]].end(), make_pair(b[i], i));
		edge[b[i]].insert(edge[b[i]].end(), make_pair(a[i], i));
	}

	int max_node = 0;
	int max_edge = 0;
	for (int i = 0; i < N; i++) {
		if (edge[i].size() > max_edge) {
			max_edge = edge[i].size();
			max_node = i;
		}
	}
	// cout << max_node + 1 << ": " << max_edge << "\n";

	// for (auto a : edge[max_node]) {
	// cout << a.first << "\n";
	// }
	// paint_node(max_node, -1, -1, edge, &c);

	class node root_node;
	root_node.k = max_node;
	root_node.parents_node = -1;
	root_node.parents_color = -1;

	st.push(root_node);
	while (st.size() > 0) {
		paint_node(st.top().k, st.top().parents_node, st.top().parents_color,
		           &edge, &c);
	}

	std::cout << max_edge << "\n";
	for (int i = 0; i < N - 1; i++) {
		std::cout << c[i] + 1 << "\n";
	}

	return 0;
}