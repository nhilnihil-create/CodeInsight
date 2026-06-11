#include <stdio.h>

typedef struct a{
	int n;
	int rep;
}node;


node t[10000];

int unite(int x,int y){
	int repx=x,repy=y;
	do{
		repx=t[repx].rep;
		
	}while(repx!=t[repx].rep);
	do{
		repy=t[repy].rep;
	}while(repy!=t[repy].rep);
	t[repx].rep=repy;
}

void search(int x,int y){
	int repx=x,repy=y;
	do{
		repx=t[repx].rep;
	}while(repx!=t[repx].rep);
	do{
		repy=t[repy].rep;
	}while(repy!=t[repy].rep);
	if(repx==repy) printf("1\n");
	else printf("0\n");
}

int main(void){
	int n,q;
	int com,x,y;
	int i,j;
	node *work;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		t[i].n=i;
		t[i].rep=i; 
	}

	while(q--){
		scanf("%d%d%d",&com,&x,&y);
		if(com==0){
			unite(x,y);
		}
		else {
			search(x,y);
		}
	}
	return 0;
}