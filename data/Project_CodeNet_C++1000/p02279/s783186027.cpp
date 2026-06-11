#include<iostream>
#include <vector>
using namespace std;
const int INVALID = -2;
enum node_type {
	root=0,
	internal_node,
	leaf
};
const char * typemsg[3] = {"root","internal node","leaf"};
class tree{
public:
	vector<int> children;
	int parent;
	int depth;
	int type;	//0:root,1:internal node, 2:leaf
	tree():parent(-1),depth(INVALID),type(1){
	}
	void print(){
		//parent = -1, depth = 0, root, [1, 4, 10]
		//parent = 1, depth = 2, leaf, []
		cout << "parent = " << parent << ", depth = " << depth << ", " << typemsg[type]
		 << ", [";
		for(int i=0;i<(int)children.size();++i) {
			if (i>0){ 
				cout << ", ";
			}
			cout  << children.at(i);
		}
		cout << "]";
	}
};

void InputSet(std::vector<int> & a) {
	int n;
	cin >> n;
	a.resize(n,0);
	for(int i=0;i<n;++i) {
		cin >> a.at(i);
	}
}
void TraverseSetDepth(vector<tree> & T,int idx,int depth){
	vector<int> & children = T[idx].children;
	for(int i=0;i<(int)children.size();++i){
		T[children[i]].depth = depth;
		TraverseSetDepth(T,children[i],depth+1);
	}
}

int main(){
	vector<tree> T;
	int n,k;
	cin >> n;
	T.resize(n);
	for(int i=0;i<n;++i) {
		cin >> k;
		InputSet(T[k].children);
		vector<int>&children = T[k].children;
		if (children.size()==0) {
			T[k].type = leaf;
		}
		else {
			for(int j=0;j<(int)children.size();++j){
				T[children[j]].parent = k;
			}
		}
	}
	for(int i=0;i<n;++i) {
		if (T[i].parent == -1){
			T[i].type = root;
			T[i].depth = 0;
			TraverseSetDepth(T,i,1);
			break;
		}
	}
	for(int i=0;i<n;++i) {
		//node 0: parent = -1, depth = 0, root, [1, 4, 10]
		cout << "node " << i << ": ";
		T[i].print();
		cout << std::endl;
	}
}