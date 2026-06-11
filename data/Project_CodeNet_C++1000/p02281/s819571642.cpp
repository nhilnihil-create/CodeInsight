#include<iostream>
#include<algorithm>
using namespace std;
#define null (-1)
#define Max 25
struct binary_tree{int parent;int left;int right;};
void pre_tree_walk(binary_tree a[],int i){

	if(i==null)
	return ;
	printf(" %d",i);
	pre_tree_walk(a,a[i].left);
	pre_tree_walk(a,a[i].right);
}
void in_tree_walk(binary_tree a[],int i){
if(i==null)
	return ;
	in_tree_walk(a,a[i].left);
	printf(" %d",i);
	in_tree_walk(a,a[i].right);
}
void po_tree_walk(binary_tree a[],int i){

	if(i==null)
	 return ;
	po_tree_walk(a,a[i].left);
	po_tree_walk(a,a[i].right);
	printf(" %d",i);
}
main(){
	int id, lf,ri,i,n;
	binary_tree a[Max];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	a[i].parent=null;
	for(i=0;i<n;i++){  
		scanf("%d %d %d",&id,&lf,&ri);
		a[id].left=lf; a[id].right=ri;
		a[lf].parent=id; a[ri].parent=id;
	}
	for(i=0;i<n;i++){
		if(a[i].parent==null)
		id=i;
	}
	
	printf("Preorder\n");
	pre_tree_walk(a,id);
	printf("\n");
	printf("Inorder\n");
	in_tree_walk(a,id);
	printf("\n");
	printf("Postorder\n");
	po_tree_walk(a,id);
	printf("\n");
	return 0;
}

