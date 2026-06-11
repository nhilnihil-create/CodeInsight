#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
const int MAX=100005;
struct Node{
	int parent,left,right,depth;
	string type;
	Node():parent(-1),left(-1),right(-1){ }
}T[MAX];
int N;
void dfs(int node,int depth){
	if(node>=N||node<0)return ;
	T[node].depth=depth;
	T[node].type="internal node";
	if(T[node].left!=-1)dfs(T[node].left,depth+1);
	else T[node].type="leaf";
	if(T[node].right!=-1)dfs(T[node].right,depth);
}
void print(int num){
	printf("node %d: parent = %d, depth = %d, %s, [",num,T[num].parent,T[num].depth,T[num].type.c_str());
	stack<int> Q;
	int p=T[num].left;
	while(p!=-1){
		Q.push(p);
		p=T[p].right;
	}
	while(!Q.empty()){
		printf("%d",Q.top());
		Q.pop();
		if(!Q.empty())printf(", ");
	}
	putchar(']');
	putchar('\n');
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		int id,k,c,c0=-1;
		cin>>id>>k;
		for(int j=0;j<k;j++){
			cin>>c;
			T[c].parent=id;
			if(c0!=-1)T[c].right=c0;
			c0=c;
		}
		T[id].left=c0;
	}
	int p=0;
	while(T[p].parent!=-1){
		p=T[p].parent;
	}
	dfs(p,0);
	T[p].type="root";
	for(int i=0;i<N;i++){
		print(i);
	}
	return 0;
}
