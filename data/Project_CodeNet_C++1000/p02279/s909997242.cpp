#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#define N 100000
using namespace std;

typedef struct{
	int parent;
	vector<int> decent;
	int dd;
} Node;
Node node[N];
int d[N];

int dep(int);
void swap(int *,int *);

int main(){
	int n,id,k,a;
	cin>>n;
	for(int i=0;i<n;i++){
		node[i].parent=-1;
		d[i]=-1;
	}
	for(int i=0;i<n;i++){
		cin>>id>>k;
		node[id].dd=k;
		for(int j=0;j<k;j++){
			cin>>a;
			node[a].parent=id;
			node[id].decent.push_back(a);
		}
	}
		for(int i=0;i<n;i++){
			if(node[i].parent==-1){
				d[i]=0;
				dep(i);
				break;
			}
		}
		for(int i=0;i<n;i++){
			printf("node %d: parent = %d, depth = %d, ",i,node[i].parent,d[i]);
			if(node[i].parent==-1){
				printf("root, [");
				for(int j=0;j<node[i].decent.size();j++){
					printf("%d",node[i].decent.at(j));
					if(j!=node[i].decent.size()-1) printf(", ");
				}
				printf("]\n");
			}else if(node[i].decent.empty()){
				printf("leaf, []\n");
			}else{
				printf("internal node, [");
				for(int j=0;j<node[i].decent.size();j++){
					printf("%d",node[i].decent.at(j));
					if(j!=node[i].decent.size()-1) printf(", ");
				}
				printf("]\n");
			}
		}
	return 0;
}

int dep(int id){
	int in=id;
		for(int i=0;i<node[id].decent.size();i++){
			in=node[id].decent.at(i);
			d[in]=d[id]+1; //???????????????????¶????
			dep(in);
		}
	return 0;
}

void swap(int *a,int *b){
	int w=*a;
	*a=*b;
	*b=w;
}