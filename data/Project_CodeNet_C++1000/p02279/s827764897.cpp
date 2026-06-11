#include<iostream>

using namespace std;

typedef struct{
	int parent,left,right,degree;
}Node;

void print(Node T[],int deep[],int n);
void setDepth(Node T[],int deep[],int u,int p);
void printChild(Node T[],int u);
void type(Node T[],int n);

int main(){
	int n;cin>>n;
	Node *T; T = new Node[n];
	for(int i=0;i<n;i++)
		T[i].parent = T[i].left = T[i].right = -1;

	for(int i=0;i<n;i++){
		int id,deg,*brother; cin>>id>>deg;
		T[id].degree = deg;
		brother = new int[deg];
		for(int j=0;j<deg;j++){
			int child; cin>>child;
			brother[j] = child;
			if(j==0)
				T[id].left = child;
			T[child].parent = id;
		}
		for(int j=0;j<deg;j++){
			if(j!=deg-1)
				T[brother[j]].right = brother[j+1];
		}
		delete [] brother;
	}

	int *deep,root;
	deep = new int[n];
	for(int i=0;i<n;i++){
		*(deep+i) = 0;
		if(T[i].parent==-1) root = i;
	}

	setDepth(T,deep,root,0);

	print(T,deep,n);

	delete [] T;
	delete [] deep;
}

void setDepth(Node T[],int deep[],int u,int p){
	deep[u] = p;
	if(T[u].right!=-1) setDepth(T,deep,T[u].right,p);
	if(T[u].left!=-1) setDepth(T,deep,T[u].left,p+1);
}

void print(Node T[],int deep[],int n){
	for(int i=0;i<n;i++){
		cout<<"node "<<i<<": parent = "<<T[i].parent<<", depth = "<<deep[i]<<", ";type(T,i);cout<<", [";printChild(T,i);cout<<"]"<<endl;
	}
}

void printChild(Node T[],int u){
	int c = T[u].left;
	while(c!=-1){
		if(T[c].right!=-1){
			cout<<c<<", ";
		}else{
			cout<<c;
		}
		c = T[c].right;
	}
}

void type(Node T[],int n){
	if(T[n].parent==-1){
		cout<<"root";
	}else if(T[n].left==-1){
		cout<<"leaf";
	}else{
		cout<<"internal node";
	}
}