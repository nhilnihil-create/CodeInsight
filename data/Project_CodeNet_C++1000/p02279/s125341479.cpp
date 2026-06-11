#include <stdlib.h>
#include <iostream>
#include <list>
using namespace std;

bool linear_search(int *array, int size, int num);
void print_children(int *children, int size);
struct graph{
	int parent_id;
	int child_num;
	int depth;
	int* children;
};
int main(){
	int n;
	cin >> n;
	graph* g = (graph*)calloc(n, sizeof(graph));
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
			//for calculating root
			g[child_id].depth = -1;
			g[id].children[j] = child_id;
		}
	}

	//calculate depth
	int depth = 0;
	while(true){
		bool does_depth_exsit = false;
		for(int i = 0; i < n; ++i){
			if(g[i].depth == depth){
				if(g[i].depth == 0) g[i].parent_id = -1;
				int child_num = g[i].child_num;
				for(int j = 0; j < child_num; ++j){
					g[g[i].children[j]].depth = depth+1;
				}
				does_depth_exsit = true;
			}
		}
		++depth;
		if(!does_depth_exsit){
			break;
		}
	}
	for(int i = 0; i < n; ++i){
		cout << "node " << i
		<< ": parent = " << g[i].parent_id
		<< ", depth = " << g[i].depth;
		if(g[i].depth == 0){
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