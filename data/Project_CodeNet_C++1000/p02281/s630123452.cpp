//By Vlgd
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int root,par[N],chl[N][2];
void pre(int v){
	if (v==-1) return;
	printf(" %d",v);
	pre(chl[v][0]);
	pre(chl[v][1]);
}
void in(int v){
	if (v==-1) return;
	in(chl[v][0]);
	printf(" %d",v);
	in(chl[v][1]);
}
void post(int v){
	if (v==-1) return;
	post(chl[v][0]);
	post(chl[v][1]);
	printf(" %d",v);
}
main(){
	int n,node,r,l;
	scanf("%d",&n);
	for (int i=0;i<n;i++) par[i]=-1;
	for (int i=0;i<n;i++){
		scanf("%d%d%d",&node,&l,&r);
		chl[node][0]=l;chl[node][1]=r;
		par[l]=par[r]=node;
	}
	for (int i=0;i<n;i++) if (par[i]==-1){root=i;break;}
	printf("Preorder\n");pre(root);printf("\n");
	printf("Inorder\n");in(root);printf("\n");
	printf("Postorder\n");post(root);printf("\n");
}
