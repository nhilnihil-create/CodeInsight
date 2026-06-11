#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <list>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

struct node{ int parent, left, right;};
node t[100000];
int n, NIL = -1, d[100000];

void print(int u) {
	int c;
	cout << "node " << u << ": parent = " << t[u].parent;
	cout << ", depth = " << d[u] << ", ";
	
	if(t[u].parent == NIL) cout <<"root, ";
	else if (t[u].left == NIL) cout << "leaf, ";
	else cout << "internal node, ";

	cout << "[";

	for(int i = 0, c = t[u].left; c != NIL; i++, c = t[c].right) {
		if(i) cout << ", ";
		cout << c;
	}
	cout << "]" <<endl;
}

void rec(int u, int p) {
	d[u] = p;
	if( t[u].right != NIL) rec(t[u].right, p);
	if( t[u].left != NIL) rec(t[u].left, p+1);
}

int main(){
	int d, v, c, l, r;
	int n; cin >> n;
	for( int i = 0; i < n; i++) t[i].left = t[i].parent = t[i].right = NIL;
	for( int i = 0; i < n; i++) {
		cin >> v >> d;
		for( int j = 0; j < d; j++) {
			cin >> c;
			if( j == 0) t[v].left = c;
			else t[l].right = c;
			l = c;
			t[c].parent = v;
		}
	}
	for( int i = 0; i < n; i++) {
		if( t[i].parent == NIL) r = i;
	}

	rec(r, 0);

	for(int i = 0; i < n; i++) print(i);

	return 0;
}