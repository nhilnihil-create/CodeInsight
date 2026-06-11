#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string nodetype[3] = {"root", "internal node", "leaf"};

struct tree{
	int parent, child, next;
};

int type(tree &node){

	if (node.parent == -1) return 0;
	else if (node.child == -1) return 2;
	else return 1;

}

int depth(vector <tree> &node, int e){
	int tmp = node[e].parent;

	if (tmp == -1) return 0;
	else return depth(node, tmp) + 1;
}

string children(vector <tree> &node, int i){
	stringstream ss;
	bool f = true;

	ss << "[";	
	int e = node[i].child;
	while (e!=-1){
		if (f) f = false;
		else ss << ", ";

		ss << e;
		e = node[e].next;
	}
	ss << "]";

	return ss.str();
}

int main(void){
	int n, e, nc, tmp, tmp2;
	string text;
	stringstream ss;

	cin >> n;
	vector <tree> node(n);
	for (int i=0; i<n; i++){
		node[i].parent = -1;
		node[i].child = -1;
		node[i].next = -1;
	}

	for (int i=0; i<n; i++){
		cin >> e;

		if (cin>>nc, nc != 0){
			for (int j=0; j<nc; j++){
				cin >> tmp;
				if (j==0) node[e].child = tmp;
				else node[tmp2].next = tmp;
				node[tmp].parent = e;
				tmp2 = tmp;
				}
		}
	}

	for (int i = 0; i<n; i++){
		ss.str("");
		ss << "node " << i <<": ";
		ss << "parent = " << node[i].parent << ", ";
		ss << "depth = " << depth(node, i) << ", ";
		e = type(node[i]);
		ss << nodetype[e] << ", ";
		ss << children(node, i);
		cout << ss.str() << endl;
	}

	return 0;
}