#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
struct node{
	int parent,leftchild,rightsibling,dep;
}tree[maxn];
int findDep(struct node t)
{
	if(t.dep!=-1)return t.dep;
	if(t.parent == -1)return t.dep = 0;
	return 	t.dep = 1 + findDep(tree[t.parent]);
}
int main()
{		
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)tree[i].parent = tree[i].leftchild = tree[i].rightsibling = tree[i].dep = -1;
	
	int id,k,c;
	for(int i=0;i<n;++i){	
		scanf("%d %d",&id,&k);
		if(k){
			int lemo;
			scanf("%d",&lemo);
			tree[lemo].parent = id;
			tree[id].leftchild = lemo;
			
			for(int i=1;i<k;++i){
				scanf("%d",&c);
				tree[c].parent = id;
				tree[lemo].rightsibling = c;
				lemo = c;
			}
		}
	}	
	for(int i=0;i<n;++i)tree[i].dep = findDep(tree[i]);
	
	for(int i=0;i<n;++i){
		printf("node %d: parent = %d, depth = %d, %s, [",i,tree[i].parent,tree[i].dep,tree[i].parent==-1?("root"):(tree[i].leftchild==-1?("leaf"):("internal node")));
		int child = tree[i].leftchild;
		if(child!=-1){printf("%d",child);child = tree[child].rightsibling;}
		while(child!=-1){
			printf(", %d",child);
			child = tree[child].rightsibling;
		}
		printf("]\n");
	}
	return 0;
}