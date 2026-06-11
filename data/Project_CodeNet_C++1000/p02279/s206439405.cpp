#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxx 100010
#define NIL -1

struct node{
	int num;
	int parent,left,right;//left is son, right is brother
};
node tree[maxx];

int get_depth(int x){
	int depth=0;
	while(tree[x].parent!=NIL){
		//cout<<"  "<<x<<"  ";
		x=tree[x].parent;
		depth++;
	}
	return depth;
}

int main (){
	for(int i=0;i<maxx;i++) {
		tree[i].parent=NIL;
		tree[i].left=NIL;
		tree[i].right=NIL;
	}
	int n;
	cin>>n;
	int a,b,c,d;
	for(int i =0;i<n;i++){
		cin>>a>>b;
		tree[i].num=a;
		for(int j=0;j<b;j++){
			if(j==0) {
				cin>>c;
				tree[tree[i].num].left=c;
				tree[c].parent=tree[i].num;
			}
			else{
				cin>>d;
				tree[c].right=d;
				tree[d].parent=tree[i].num;
				c=d;
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, ",i,tree[i].parent,get_depth(i));
		if(tree[i].parent==NIL) printf("root, [");
		else if(tree[i].left==NIL) printf("leaf, [");
		else printf("internal node, [");
		if(tree[i].left!=NIL) {
			printf("%d",tree[i].left);
			int xx=tree[i].left;
			while(tree[xx].right!=NIL){
				printf(", %d",tree[xx].right);
				xx=tree[xx].right;
			}
		}
		printf("]\n");
	}
	return 0;
}
