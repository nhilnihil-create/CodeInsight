#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node{int key; Node *p,*l,*r;};
Node *null,*root;


void insert(int k){
Node *x,*y,*z;
	y=null;
	x=root;
	z=(Node*)malloc(sizeof(Node));
	z->key=k;
	z->l=null;
	z->r=null;
	while(x!=null){
	    y=x;
		if(z->key<x->key)
		x=x->l;
		else 
		x=x->r;
	}
	z->p=y;
	if(y==null)
	root=z;
	else if(z->key>y->key)
	y->r=z;
	else
	y->l=z;
}
void in_p(Node *u){
	if(u==null)
	return;
	in_p(u->l);
	printf(" %d",u->key);
	in_p(u->r);
}
void pre_p(Node *u){
	if(u==null)
	return ;
	printf(" %d",u->key);
	pre_p(u->l);
	pre_p(u->r);
}
void print(){
	in_p(root);
	printf("\n");
	pre_p(root);
	printf("\n");
}
bool find(Node *a,int k){
	if(a==null)
	return false;
	    else if(a->key==k)
		return true;
		else if(a->key>k)
	     find(a->l,k);
	    else 
	    find(a->r,k);
	}

main(){
	int i,n,key;
	string com;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		cin>>com;
		if(com=="insert"){
			scanf("%d",&key);
			insert(key);
		}
		else if(com=="find"){
			scanf("%d",&key);
			if(find(root,key))
			printf("yes\n");
			else
			printf("no\n");
		}
		else
		print();
	}
	
	return 0;
}

