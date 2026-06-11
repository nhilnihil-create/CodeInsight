#include<iostream>
#include<cstdio>

using namespace std;

struct Node{int p, l, r;};
// Parent Left-child Right-sibling

Node T[100001];
int n,D[100001];

void resprint(int u){
	printf("node %d: ",u);
	printf("parent = %d, ",T[u].p);
	printf("depth = %d, ",D[u]);
	if(T[u].p==-1)
	printf("root, ");
	else if(T[u].l==-1)
	printf("leaf, ");
	else
	printf("internal node, ");
	
	int c;
	printf("[");
	for(int i=0,c=T[u].l ; c!=-1 ; i++,c=T[c].r){
		if(i!=0)
		printf(", ");
		printf("%d",c);
	}
	printf("]\n");
}

void depth(int u, int p){
	D[u]=p;
	if(T[u].r!=-1)
	depth(T[u].r,p); //???????????????, ???????????±????¨????
	if(T[u].l!=-1)
	depth(T[u].l,p+1); //??????????????????, ???????????±???+1?¨????
}

int main(){
	int l,r,id,k,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		T[i].p=-1;
		T[i].l=-1;
		T[i].r=-1;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&c);
			if(j==0)
			T[id].l=c;
			else
			T[l].r=c;
			l=c;
			T[c].p=id;
		}
	}
	for(int i=0;i<n;i++){
		if(T[i].p==-1)
		r=i;
	}
	depth(r,0);
	for(int i=0;i<n;i++){
		resprint(i);
	}
}