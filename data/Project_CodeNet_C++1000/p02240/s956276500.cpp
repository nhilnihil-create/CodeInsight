#include <iostream>
#include <vector>
#include <queue>

struct Node {
	int ID;
	int rep;
	bool visited;
	bool operator<(const Node& rhs) {return this->ID < rhs.ID;}
	bool operator>(const Node& rhs) {return this->ID > rhs.ID;}
	bool operator<=(const Node& rhs) {return this->ID <= rhs.ID;}
	bool operator>=(const Node& rhs) {return this->ID >= rhs.ID;}
	bool operator==(const Node& rhs) {return this->ID == rhs.ID;}
	bool operator!=(const Node& rhs) {return this->ID != rhs.ID;}
};

void BFS(std::vector<int>* adjlist, Node* nodes, std::queue<int> que)
{	
	while (!que.empty()) {
		int id = que.front(); que.pop();
		for (std::vector<int>::iterator it = adjlist[id].begin(); it != adjlist[id].end(); ++it) {
			if (!nodes[*it].visited) { 
				que.push(*it);
				nodes[*it].rep = nodes[id].rep;
				nodes[*it].visited = true;
			}
		}
	}
}

void DFS(std::vector<int>* adjlist, Node* nodes, int id, int rep)
{
	nodes[id].rep = rep;
	nodes[id].visited = true;
	
	for (std::vector<int>::iterator it = adjlist[id].begin(); it != adjlist[id].end(); ++it) {
		if (!nodes[*it].visited) DFS(adjlist, nodes, *it, rep);
	}
}

int main()
{
	int n, m; std::cin >> n >> m;
	
	std::vector<int>* adjlist = new std::vector<int>[n];
	Node* nodes = new Node[n];
	
	std::queue<int> que;
	
	for (int i=0; i<n; i++) {
		nodes[i].visited = false;
	}
	
	for (int i=0; i<m; i++) {
		int x, y;
		std::cin >> x >> y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
	}
	
	//std::sort(nodes, nodes + n);
	
	for (int i=0; i<n; i++) {
		if (!nodes[i].visited) {
			//que.push(i); nodes[i].visited = true; nodes[i].rep = i;
			//BFS(adjlist, nodes, que);
			DFS(adjlist, nodes, i, i);
		}
	}
	
	int q; std::cin >> q;
	
	for (int i=0; i<q; i++) {
		int x, y;
		std::cin >> x >> y;
		if (nodes[x].rep == nodes[y].rep) std::cout << "yes" << std::endl;
		else std::cout << "no" << std::endl;
	}
	
	delete[] adjlist;
	delete[] nodes;
	
	return 0;
}

