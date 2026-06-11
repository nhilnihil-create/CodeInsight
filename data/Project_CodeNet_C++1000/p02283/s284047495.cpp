//By Vlgd
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	node *l,*r,*p;
};
node* root=NULL;
void insert(int x){
	node *n=(node*)malloc(sizeof(node));
	n->x=x;
	n->r=n->l=NULL;
	node *tmp=root,*fa=NULL;
	while(tmp!=NULL){
		fa=tmp;
		if (x<tmp->x) tmp=tmp->l; 
		else tmp=tmp->r;
	}
	n->p=fa;
	if (fa==NULL){
		root=n;
	}
	else{
		if (x<fa->x) fa->l=n;
		else fa->r=n;
	}	
}
void ino(node *T){
	if (T!=NULL){
		ino(T->l);
		printf(" %d",T->x);
		ino(T->r);
	}
}
void pre(node *T){
	if (T!=NULL){
		printf(" %d",T->x);
		pre(T->l);
		pre(T->r);
	}
}
main(){
	int n,xx;
	string ins;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		cin>>ins;
		if (ins=="insert"){
			scanf("%d",&xx);
			insert(xx);
		}
		else if (ins=="print"){
			ino(root);printf("\n");
			pre(root);printf("\n");
		}
	}
}
