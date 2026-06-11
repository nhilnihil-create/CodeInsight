#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define NIL -1

using namespace std;

struct node{
	int pa;
	int le;
	int ri;
};

const int maxn=1e7+10;
node nd[maxn];
int deep[maxn];

void Init(int n)
{
	for(int i=0;i<n;i++){
		nd[i].pa=nd[i].le=nd[i].ri=NIL;
	}
}

void setDepth(int u,int p)
{
	deep[u]=p;
	if(nd[u].ri!=NIL){
		setDepth(nd[u].ri,p);
	}
	if(nd[u].le!=NIL){
		setDepth(nd[u].le,p+1);
	}
}

void print_node(int n)
{
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d,",i,nd[i].pa,deep[i]);
		if(nd[i].pa==NIL){
			printf(" root, ");
		}else if(nd[i].le==NIL){
			printf(" leaf, ");
		}else{
			printf(" internal node, ");
		}
		printf("[");
		for(int j=0,c=nd[i].le;c!=NIL;c=nd[c].ri,j++){//打印同层子节点 
			if(j>0)printf(", ");
			printf("%d",c);
		}
		printf("]\n");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	Init(n);//用for循环初始化空间复杂度更小，但是跑的更慢，到了test7就tle了 
	//memset(nd,NIL,sizeof(nd));用这段代码进行初始化，时间上的确更快了，但是空间复杂度一下就大了，memory limit exceed 
	memset(deep,0,sizeof(deep));
	int v,d,c,l,root;
	for(int k=0;k<n;k++){
		scanf("%d%d",&v,&d);
		for(int i=0;i<d;i++){
			scanf("%d",&c);
			if(i==0){
				nd[v].le=c;
			}else{
				nd[l].ri=c;
			}
			l=c;
			nd[c].pa=v;
		}
		/*for(int i=0;i<n;i++){
			if(nd[i].pa==NIL)root=i;//寻找根节点 
		}
		setDepth(root,0);*/
	}
	for(int i=0;i<n;i++){
			if(nd[i].pa==NIL)root=i;//寻找根节点 
	}
	setDepth(root,0);
	print_node(n);
	return 0;
}
