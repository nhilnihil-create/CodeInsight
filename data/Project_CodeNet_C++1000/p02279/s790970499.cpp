#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node{int p,l,r;};
Node T[MAX];
int D[MAX];

void print(int i){
	cout << "node " << i << ": parent = ";
	cout << T[i].p << ", depth = " << D[i] << ", ";
	if(T[i].p==NIL)cout << "root";
	else if(T[i].l==NIL)cout << "leaf";
	else cout << "internal node";

	cout << ", [";

	int c=T[i].l;
	for(int i=0;c!=NIL;i++,c = T[c].r){
		cout << (i?", ":"") << c;
	}
	cout << "]" << endl;
}

void rec(int u,int d){
	D[u] = d;
	if(T[u].r != NIL)rec(T[u].r,d);
	if(T[u].l != NIL)rec(T[u].l,d+1);
}

int main(){
	int n,i,k,r,a=NIL,b=NIL;
	cin >> n;
	for(int j=0;j<n;j++)T[j].p=T[j].l=T[j].r=NIL;
	for(int s=0;s<n;s++){
		cin >> i >> k;
		for(int j=0;j<k;j++){
			b = a;
			cin >> a;
			if(j==0)T[i].l = a;
			else T[b].r = a;
			T[a].p = i;
		}
	}
	for(int j=0;j<n;j++){
		if(T[j].p == NIL) r=j;
	}

	rec(r,0);
	for(int j=0;j<n;j++)print(j);

	return 0;
}

