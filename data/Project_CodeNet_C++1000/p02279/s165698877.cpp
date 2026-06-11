#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

struct Node{
	int p;
	int l;
	int r;
};
const int MAXN = 1e5+10;
const int NIL = -1;

Node T[MAXN];
int n,D[MAXN];

void print(int u){
	int i,c;
	cout << "node "<<u<<": ";
	cout << "parent = "<< T[u].p<<", ";
	cout << "depth = " << D[u]<<", ";
	
	if(T[u].p==NIL)	cout<<"root, ";
	else if(T[u].l==NIL)	cout<<"leaf, ";
	else	cout<<"internal node, ";
	
	cout << "[";
	
	for(i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
		if(i)	cout<<", ";
		cout << c;
	}
	cout <<"]"<<endl;
}

int rec(int u, int p){
	D[u] = p;
	if(T[u].r!=NIL)	rec(T[u].r,p);
	if(T[u].l!=NIL)	rec(T[u].l,p+1);
}

int main(){
	int i,j,d,v,c,l,r;
	cin>>n;
	for(i=0;i<n;i++){
		T[i].p = T[i].l = T[i].r=NIL;
	}
	
	for(i=0;i<n;i++){
		cin>>v>>d;
		for(j=0;j<d;j++){
			cin >>c;
			if(j==0)	T[v].l=c;
			else T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	for(i=0;i<n;i++){
		if(T[i].p==NIL)	r = i;
	}

	rec(r,0);

	for(i=0;i<n;i++)	print(i);

	return 0;
}


