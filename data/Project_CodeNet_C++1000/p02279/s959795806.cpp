#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
const int NIL = -1;
const int MAXN = 100005;

struct Node{ int p, l, r;}T[MAXN];

int n, D[MAXN];

void print(int u){
	cout << "node " << u << ": parent = " << T[u].p;
	cout << ", depth = " << D[u] <<", ";
	if(T[u].p == NIL)	cout <<"root, [";
	else if(T[u].l == NIL)	cout << "leaf, [";
	else	cout << "internal node, [";
	for(int c = T[u].l, i = 0; c != NIL; c = T[c].r, i++){
		if(i)
			cout << ", ";
		cout << c;
	}
	cout << "]" <<endl;
}

void setDepth(int u, int p){
	D[u] = p;
	if(T[u].r != NIL)
		setDepth(T[u].r
			, p);
	if(T[u].l != NIL)
		setDepth(T[u].l, p + 1);
}

int main(){
	cin >> n;
	int p, num, temp, l, loc;
	for(int i = 0; i < n; i++)	T[i].p = T[i].l = T[i].r = NIL;	
	for(int i = 0; i < n; i++){
		cin >> p >> num;
		for(int j = 0; j < num; j++){
			cin >> temp;
			if(!j)
				T[p].l = temp;
			else
				T[l].r = temp;
			l = temp;
			T[l].p = p;
		}
	}
	for(int i = 0; i < n; i++)
		if(T[i].p == NIL)
			loc = i;
	setDepth(loc, 0);
	for(int i = 0; i < n; i++)	print(i);
	return 0;
}