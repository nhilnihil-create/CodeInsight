#include <iostream>
#include<string>
#include <algorithm>
#define NIL -1
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct Node { int p, l, r; };
struct Node t[100000];
int D[100000];

void print(int u) {
	cout << "node " << u << ": parent = " << t[u].p << ", depth = "<<D[u]<<", ";
	if (t[u].p == NIL) {
		cout << "root, ";
	}
	else if (t[u].l == NIL) {
		cout << "leaf, ";
	}
	else {
		cout << "internal node, ";
	}
	cout << "[";
	for (int i = 0, c = t[u].l; c != NIL; i++, c = t[c].r) {
		if (i) {
			cout << ", " << c;
		}
		else {
			cout << c;
		}
	}
cout << "]"<<endl;
}
int rec(int u, int p) {
	D[u] = p;
	if (t[u].r != NIL) {
		rec(t[u].r, p);
	}
	if (t[u].l != NIL) {
		rec(t[u].l, p+1);
	}
	return 0;
}

int main()
{
	int r;
	int n; cin >> n;
	REP(i, n) {
		t[i].p = t[i].l = t[i].r = NIL;
	}
	REP(i, n) {
		int id, k,j; cin >> id >> k;
		REP(i, k) {
			int c; cin >> c;
			if (i == 0) {
				t[id].l = c;
			}
			else {
				t[j].r = c;
			}
			j = c;
			t[c].p = id;
		}
	}
	REP(i, n) {
		if (t[i].p == NIL) {
			r = i; break;
		}
	}
	rec(r, 0);
	REP(i, n) {
		print(i);
}
	return 0;
}