#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define Max 200
struct Node{int key;Node *p,*l,*r;};
Node *null,*root;
void init(){

	null=(Node*)malloc(sizeof(Node));
	null->p=null;
	null->l=null;
	null->r=null;
	root=null;
	
}
void inseart(int k){	
Node *y,*x,*z;
	y=null;x=root;
	z=(Node*)malloc(sizeof(Node));
	z->key=k;
	z->l=null;
	z->r=null;
	while(x!=null){
	y=x;
		if(z->key < x->key)
		  x=x->l;
		else 
		  x=x->r;
	}
	z->p=y;
	if(y==null)
	  root=z;
	else if(z->key<y->key)
	  y->l=z;
	else 
	  y->r=z;
}
void pre_walk(Node *a){
	if(a==null)
	return;
	printf(" %d",a->key);
	pre_walk(a->l);
	pre_walk(a->r);
}
void in_walk(Node *a){
	if(a==null)
	return;
	in_walk(a->l);
	printf(" %d",a->key);
	in_walk(a->r);
}
main(){
	int n,i,key;
	char ord[20];
	scanf("%d",&n);
		init();
	for(i=0;i<n;i++){
		scanf(" %s",ord);
		if(ord[0]=='i'){
			scanf("%d",&key);
			inseart(key);
		}
		else {
            in_walk(root);
			printf("\n");
			pre_walk(root);
			printf("\n");
		}
	}
	
	return 0;
}

