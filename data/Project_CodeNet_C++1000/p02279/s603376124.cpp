#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
class Tree{
	int Id;
	int parent;
	int depth;
	string type;
	int left, right;
public:
	Tree(){ Id = 0, parent = -1, depth = 0, type = "", left = -1, right = -1; }
	void setId(int a){ this->Id = a; }
	void setParent(int a){ this->parent = a; }
	int takeId(){ return this->Id; }
	int takeParent(){ return this->parent; }
	int takeDepth(){ return this->depth; }
	int takeLeft(){ return this->left; }
	int takeRight(){ return this->right; }
	string takeType(){ return this->type; }
	void setDepth(int a){ this->depth = a; }
	void setLeft(int a){ this->left = a; }
	void setRight(int a){ this->right = a; }
	void setType(){
		if (this->parent == -1) this->type = "root";
		else if (this->left == -1) this->type = "leaf";
		else this->type = "internal node";
	}
};
Tree nodes[100001];
void printChildren(int parentId){
	int i = nodes[parentId].takeLeft();
	if (i == -1) return;
	cout << i;
	i = nodes[i].takeRight();
	while (i != -1){
		cout << ", " << i;
		i = nodes[i].takeRight();
	}
}
void print(int Id){
	nodes[Id].setType();
	cout << "node " << Id << ": parent = " << nodes[Id].takeParent()
		<< ", depth = " << nodes[Id].takeDepth() << ", " << nodes[Id].takeType()
		<< ", [";
	printChildren(Id);
	cout << "]\n";
}
void makeDepth(int NODE, int depth){
	nodes[NODE].setDepth(depth);
	int LEFT = nodes[NODE].takeLeft();
	if (LEFT != -1) makeDepth(LEFT,depth+1);
	int RIGHT = nodes[NODE].takeRight();
	if (RIGHT != -1) makeDepth(RIGHT, depth);
	return;
}
int main(){
	int n; scanf("%d",&n);
	for (int i = 0; i < n;++i){
		int id, k, childId; scanf("%d %d", &id, &k);
		nodes[id].setId(id);
		int NODE = id;
		for (int j = 0; j < k; ++j){
			scanf("%d", &childId);
			if (j == 0){
				nodes[NODE].setLeft(childId);
			}
			else{
				nodes[NODE].setRight(childId);
			}
			nodes[childId].setParent(id);
			NODE = childId;
		}
	}
	int p = -1;
	for (int i = 0; i < n; ++i) if (nodes[i].takeParent() == -1) { p = i; break; }
	makeDepth(p,0);
	for (int i = 0; i < n; ++i) print(i);
}