#include <stdlib.h>
#include <iostream>
#include <list>
using namespace std;

struct node{
	int parent_id;
	int child_num;
	int* children;
};
void print_children(int *children, int size);
int get_depth(node* g, int id);
int main(){
	int n;
	cin >> n;
	node* g = (node*)calloc(n, sizeof(node));
	// initialize
	for(int i = 0; i < n; ++i){
		g[i].parent_id = -1;
	}
	//input data
	for(int i = 0; i < n; ++i){
		int id;
		int child_num;
		cin >> id;
		cin >> child_num;
		g[id].child_num = child_num;
		g[id].children = (int*)malloc(child_num * sizeof(int));
		for(int j = 0; j < child_num; ++j){
			int child_id;
			cin >> child_id;
			g[child_id].parent_id = id;
			g[id].children[j] = child_id;
		}
	}

	for(int i = 0; i < n; ++i){
		cout << "node " << i
		<< ": parent = " << g[i].parent_id
		<< ", depth = ";
		int depth = get_depth(g, i);
		cout << depth;
		if(depth == 0){
			cout << ", root";
		}else{
			if(g[i].child_num == 0){
				cout << ", leaf";
			}else{
				cout << ", internal node";
			}
		}
		cout << ", [";
		print_children(g[i].children, g[i].child_num);
		cout << "]" << endl;
	}
	return 0;
}

void print_children(int *children, int size){
	for(int j = 0; j < size; ++j){
		 	cout << children[j];
		 	if(j != size-1){
		 		cout << ", ";
		 	}
	}

}
int get_depth(node* g, int id){
	int depth = 0;
	int current_id = id;
	while(g[current_id].parent_id != -1){
		++depth;
		current_id = g[current_id].parent_id;
	}
	return depth;
}