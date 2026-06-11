#include <iostream>
#include <stdio.h>
#define N_MAX 25
#define NIL -1
using namespace std;
//thik&solve easy 

int n;

class node{
public:
	int parent;
	int left_chld;
	int right_chld;
};

node BT[N_MAX+1];


void preorder(int u){
	int pos;
	cout <<" " <<u;

	if(BT[u].left_chld != NIL){
		pos = BT[u].left_chld;
		preorder(pos);
	}

	if(BT[u].right_chld != NIL){
		pos = BT[u].right_chld;
		preorder(pos);
	}
	
	return;
}

void inorder(int u){
	int pos;

	if(BT[u].left_chld != NIL){
		pos = BT[u].left_chld;
		inorder(pos);
	}
	cout <<" " <<u;

	if(BT[u].right_chld != NIL){
		pos = BT[u].right_chld;
		inorder(pos);
	}
	
	return;
}

void postorder(int u){
	int pos;

	if(BT[u].left_chld != NIL){
		pos = BT[u].left_chld;
		postorder(pos);
	}

	if(BT[u].right_chld != NIL){
		pos = BT[u].right_chld;
		postorder(pos);
	}
	cout <<" " <<u;
	
	return;
}

int main(){
	//初期化
	for(int i=0;i<N_MAX;i++){
		BT[i].parent = BT[i].left_chld = BT[i].right_chld = NIL;
	}
	//

	int id_tmp;
	int lchld_tmp;
	int rchld_tmp;
	int root;

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&id_tmp);
		scanf("%d",&lchld_tmp);
		scanf("%d",&rchld_tmp);

		BT[id_tmp].left_chld = lchld_tmp;
		BT[id_tmp].right_chld = rchld_tmp;

		BT[lchld_tmp].parent = BT[rchld_tmp].parent = id_tmp;
	}

	for(int i=0;i<n;i++){
		if(BT[i].parent == NIL){
			root = i;
			break;
		}
	}

	cout <<"Preorder" <<endl;
	preorder(root);
	cout <<endl;

	cout <<"Inorder" <<endl;
	inorder(root);
	cout <<endl;

	cout <<"Postorder" <<endl;
	postorder(root);
	cout <<endl;

}