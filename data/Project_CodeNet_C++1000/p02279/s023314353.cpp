#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1
struct Node{
	int p,l,r;
}T[MAX];
int n,depth[MAX];
void print(int root){
	cout<<"node "<<root<<": ";
	cout<<"parent = "<<T[root].p<<", ";
	cout<<"depth = "<<depth[root]<<", ";
	if(T[root].p==NIL) cout<<"root, ";
	else if(T[root].l==NIL) cout<<"leaf, ";
	else cout<<"internal node, ";
	cout<<"[";
	for(int i=0,c=T[root].l;c!=NIL;i++,c=T[c].r){
		if(i) cout<<", ";
		cout<<c;
	}
	cout<<"]"<<endl;
}
void rec(int root,int p){
	depth[root]=p;
	if(T[root].r!=NIL) rec(T[root].r,p);
	if(T[root].l!=NIL) rec(T[root].l,p+1);
}
int main(){
	int l;
	cin>>n;
	for(int i=0;i<n;i++){
		T[i].p=T[i].l=T[i].r=NIL;
	}
	for(int i=0;i<n;i++){
		int v,d;
		cin>>v>>d;
		for(int j=0;j<d;j++){
			int node;
			cin>>node;
			if(!j) T[v].l=node;
			else T[l].r=node;
			l=node;
			T[node].p=v;
		}
	}
	int root;
	for(int i=0;i<n;i++){
		if(T[i].p==NIL) root=i;
	}
	rec(root,0);
	for(int i=0;i<n;i++) print(i);
}