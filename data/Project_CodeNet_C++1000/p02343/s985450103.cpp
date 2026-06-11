#include <cstdio>
using namespace std;

int parent[10000];

int find_parent(int x){
	if(x!=parent[x])	parent[x]=find_parent(parent[x]);
	return parent[x];
}

int main(){
	int n,q;	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)	parent[i]=i;
	int com,x,y;
	while(q--){
		scanf("%d %d %d",&com,&x,&y);
		if(com==0){
			y=find_parent(y);
			x=find_parent(x);
			parent[y]=x;
		}
		else if(com==1){
			if(find_parent(x)==find_parent(y))	printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}