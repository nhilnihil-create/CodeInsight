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
void setDep(int u,int d){
	tree[u].dep = d;
	if(tree[u].rightsibling!=-1)setDep(tree[u].rightsibling,d);
	if(tree[u].leftchild!=-1)setDep(tree[u].leftchild,d+1);
}
int main()
{		
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)tree[i].parent = tree[i].leftchild = tree[i].rightsibling = tree[i].dep = -1;
	
	int id,k,c,rootid;
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
	for(int i=0;i<n;++i)if(tree[i].parent == -1){rootid = i;break;}
	
	setDep(rootid,0);
	
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