#include<iostream>

int main() {
	int node_num, adj[100][100];

	std::cin >> node_num;

	for (int i = 0; i < node_num; i++)
		for (int j = 0; j < node_num; j++)
			adj[i][j] = 0;

	for (int i = 0; i < node_num; i++) {
		int node, num;
		std::cin >> node >> num;
		for (int j = 0; j < num; j++) {
			int n;
			std::cin >> n;
			adj[node - 1][n - 1] = 1;
		}
	}

	for (int i = 0; i < node_num; i++) {
		for (int j = 0; j < node_num; j++) {
			std::cout << adj[i][j] << (j != node_num - 1 ? " ":"");
		}
		std::cout << std::endl;
	}
}