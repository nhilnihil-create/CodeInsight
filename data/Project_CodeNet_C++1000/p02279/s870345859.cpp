#include<iostream>
#include<vector>
using namespace std;

struct NODE{
	int id = -100;
	int parent = -1;
	int num_children = -100;
	int depth = -100;
	vector<int> children;
};

void check_depth(NODE *nodes, int id, int d){
	nodes[id].depth = d;	

	for(int i=0; i<nodes[id].num_children; ++i){
		check_depth(nodes, nodes[id].children[i], d+1);
	}
}

void show(NODE *nodes, const int &n){
	for(int i=0; i<n; ++i){
		cout << "node " << nodes[i].id << ": ";
		cout << "parent = " << nodes[i].parent << ", ";
		cout << "depth = " << nodes[i].depth << ", ";

		if(nodes[i].parent == -1){
			cout << "root, ";
		}else if(nodes[i].num_children == 0){
			cout << "leaf, ";
		}else{
			cout << "internal node, ";
		}

		cout << "[";
		for(int j=0; j<nodes[i].num_children; ++j){
			cout << nodes[i].children[j];

			if(j != nodes[i].num_children - 1)
				cout << ", ";
		}
		cout << "]";

		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;

	NODE *nodes = new NODE[n];
	int n_children;
	int temp;
	int id;
	for(int i=0; i<n; ++i){
		cin >> id >> n_children;
		nodes[id].id = id;
		nodes[id].num_children = n_children;
	
		for(int j=0; j<n_children; ++j){
			cin >> temp;
			nodes[id].children.push_back(temp);
			nodes[temp].parent = id;
		}
	}	

	// Find root
	int root_id;
	for(int i=0; i<n; ++i){
		if(nodes[i].parent == -1){
			root_id = i;
			break;
		}
	}

	check_depth(nodes, root_id, 0);	
	show(nodes, n);

	return 0;
}
