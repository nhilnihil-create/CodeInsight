#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Node {
public:
	int ID;
	int parent;
	int depth;
	std::string type; // root, internal node, leaf
	std::vector<int> children;
public:
	Node() { ID = 0; parent = -1; depth = 0; type = "root"; }
	Node(int ID, std::vector<int> children) { this->ID = ID; this->children = children;}
	Node(int ID, int parent, int depth, std::string type, std::vector<int> children) {
		this->ID = ID; this->parent = parent; this->depth = depth;
		this->type = type;
		this->children = children;
	}
	bool operator<(const Node& rhs) { return this->ID < rhs.ID; }
	bool operator<=(const Node& rhs) { return this->ID <= rhs.ID; }
	bool operator>(const Node& rhs) { return this->ID > rhs.ID; }
	bool operator>=(const Node& rhs) { return this->ID >= rhs.ID; }
	bool operator==(const Node& rhs) { return this->ID == rhs.ID; }
	bool operator!=(const Node& rhs) { return this->ID != rhs.ID; }
	~Node(){}
};

int get_index_from_ID(Node* rtree, int n, int ID)
{
	int lb = 0;
	int ub = n-1;
	while (lb+1 < ub) {
		int mid = (lb + ub) / 2;
		if (rtree[mid].ID == ID) return mid;
		else if (rtree[mid].ID < ID) lb = mid;
		else ub = mid;
	}
	if (rtree[lb].ID == ID) return lb;
	else if (rtree[ub].ID == ID) return ub;
	
	return -1;
}

void compute_the_rest(Node* rtree, int n, int index_of_node)
{
	for (int j=0; j<rtree[index_of_node].children.size(); j++) {
		int index_of_child = get_index_from_ID(rtree, n, rtree[index_of_node].children[j]);
		rtree[index_of_child].parent = rtree[index_of_node].ID;
		rtree[index_of_child].depth  = rtree[index_of_node].depth + 1;
		rtree[index_of_child].type   = rtree[index_of_child].children.empty() ? "leaf" : "internal node";
		compute_the_rest(rtree, n, index_of_child);
	}
}

int main()
{
	int n;
	std::cin >> n;
	
	Node* rtree = new Node[n];
	
	for (int i=0; i<n; i++) {
		int ID;
		int num_of_children;
		std::cin >> ID >> num_of_children;
		std::vector<int> children;
		for (int j=0; j<num_of_children; j++) {
			int child;
			std::cin >> child;
			children.push_back(child);
		}
		rtree[i] = Node(ID, children);
	}
	
	std::sort(rtree, rtree + n);
	
	bool* isRoot = new bool[n];
	for (int i=0; i<n; i++) isRoot[i] = true;
	
	// assign false for every node appearing in the children lists
	for (int i=0; i<n; i++) {
		for (int j=0; j<rtree[i].children.size(); j++) {
			int index_of_child = get_index_from_ID(rtree, n, rtree[i].children[j]);
			isRoot[index_of_child] = false;
		}
	}
	
	// search the index of the root node
	int index_of_root = -1;
	for (int i=0; i<n; i++) {
		if (isRoot[i]) { index_of_root = i; break; }
	}
	
	rtree[index_of_root].parent = -1;
	rtree[index_of_root].depth  = 0;
	rtree[index_of_root].type   = "root";
	
	// std::cout << "root node = " << rtree[index_of_root].ID << std::endl;
	
	compute_the_rest(rtree, n, index_of_root);
	
	
	
	// output
	for (int i=0; i<n; i++) {
		std::cout << "node " << rtree[i].ID << ": parent = " << rtree[i].parent << ", depth = "
				  << rtree[i].depth << ", " << rtree[i].type << ", [";
		for (int j=0; j<rtree[i].children.size(); j++) {
			if (j>0) std::cout << ", ";
			std::cout << rtree[i].children[j];
		}
		std::cout << "]" << std::endl;
	}
	
	delete[] isRoot;
	delete[] rtree;
	
	return 0;
}


