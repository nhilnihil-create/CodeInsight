#include <iostream>
#include <vector>
using namespace std;

struct node { int parent,depth; vector<int> child; };

vector<node> tree;

void dfs(int num){
	if(tree[num].child.size() == 0) return;
	for(int i = 0;i < tree[num].child.size();i++){
		tree[tree[num].child[i]].depth = tree[num].depth + 1;
		dfs(tree[num].child[i]);
	}
}

int main(){
	int n,m,now,t;
	cin >> n;
	tree.resize(n);
	for(int i = 0;i < n;i++){
		cin >> now >> m;
		vector<int> vec;
		for(int j = 0;j < m;j++){
			cin >> t;
			vec.push_back(t);
		}
		tree[now] = {-1,0,vec};
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < tree[i].child.size();j++) tree[tree[i].child[j]].parent = i;
	}
	int par;
	for(int i = 0;i < n;i++){
		if(tree[i].parent == -1) par = i;
	}
	dfs(par);
	for(int i = 0;i < n;i++){
		cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << tree[i].depth;
		if(tree[i].parent == -1) {
			cout << ", root, [";
			if(tree[i].child.size() != 0) cout << tree[i].child[0];
			for(int j = 1;j < tree[i].child.size();j++) cout << ", " << tree[i].child[j];
			cout << "]" << endl;
		}
		else if(tree[i].child.size() == 0) cout << ", leaf, []" << endl;
		else {
			cout << ", internal node, [" << tree[i].child[0];
			for(int j = 1;j < tree[i].child.size();j++) cout << ", " << tree[i].child[j];
			cout << "]" << endl;
		}
		
	}
	return 0;
}