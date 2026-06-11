//============================================================================
// Name        : RootedTree.cpp
// Author      : Ken
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
	int id;
	Node* p_parent;
	vector<Node*> p_children;

	Node(int n):id(n), p_parent(), p_children(){}
	Node(int n, Node& supernode):id(n), p_parent(&supernode), p_children(){}
};

void initializeNodes(vector<Node>& nodes, int n, Node& supernode){
	for(int i=0; i<n; i++){
		nodes.push_back(Node(i, supernode));
	}
}

string checkNodeType(vector<Node>& nodes, int i){
	if(i>=nodes.size()){
		cout << "ERROR!\n";
	}

	if(nodes.at(i).p_parent->id == -1){
		return "root";
	}

	if(nodes.at(i).p_children.size()==0){
		return "leaf";
	}

	return "internal node";
}

int checkDepth(vector<Node>& nodes, int i){
	if(i>=nodes.size()){
		cout << "ERROR!\n";
	}

	int depth = 0;
	Node* p_parent = nodes.at(i).p_parent;
	int id = p_parent->id;
	while(id != -1){
		depth ++;
		p_parent = p_parent->p_parent;
		id = p_parent->id;
	}

	return depth;
}

void writeTree(vector<Node>& nodes){
	//for(int i=0; i<nodes.size(); i++){
	//	cout << "node " << nodes.at(i).id << "\n";
	//}

	for(int i=0; i<nodes.size(); i++){
		cout << "node " << nodes.at(i).id << ": parent = " << nodes.at(i).p_parent->id;

		int depth = checkDepth(nodes, i);
		cout << ", depth = " << depth;


		string nodeType = checkNodeType(nodes, i);
		cout << ", " << nodeType;

		cout << ", [";
		int n_children = nodes.at(i).p_children.size();
		if(n_children>0){
		    for(int j=0; j<n_children-1; j++){
			    cout << nodes.at(i).p_children.at(j)->id << ", ";
		    }
		cout << nodes.at(i).p_children.at(n_children-1)->id;
		}
		cout << "]\n";
	}
}

int main() {
	int n;
	cin >> n;
	vector<Node> nodes;
	Node SuperNode(-1);

	initializeNodes(nodes, n, SuperNode);

	//writeTree(nodes);

	for(int i=0; i<n; i++){
		//cout << "here: " << i << "\n";
		int id, m;
		cin >> id >> m;

		if(m==0){
			//cout << "continue: " << i << "\n";
			continue;
		}

		for(int j=0; j<m; j++){
			int child;
			cin >> child;
			nodes.at(id).p_children.push_back(&(nodes.at(child)));
			nodes.at(child).p_parent = &(nodes.at(id));
		}

	}

	//cout << "here3";
	writeTree(nodes);

	return 0;
}

