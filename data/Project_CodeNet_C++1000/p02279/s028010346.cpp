#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;
int N;

struct Node { int parent, left, right; };
int NIL = -1;

// left-child, right-sibling representation;
Node Nodes[MAX_N];

int depth(int i){
	if (Nodes[i].parent == NIL) return 0;
	return depth(Nodes[i].parent) + 1;
}

string attr(int i){
	if (Nodes[i].parent == NIL) return "root";
	if (Nodes[i].left == NIL) return "leaf";
	return "internal node";
}

vint children(int i){
	vint ret;
	int c = Nodes[i].left;
	if (c != NIL){
		ret.push_back(c);
		while (true){
			int s = Nodes[c].right;
			if (s == NIL) break;
			ret.push_back(s);
			c = s;
		}

	}
	return ret;
}

int main() {

	// construct tree
	cin >> N;
	
	rep(i, N){
		Nodes[i].left = NIL;
		Nodes[i].parent = NIL;
		Nodes[i].right = NIL;
	}

	rep(i, N){
		int p; cin >> p;
		int n; cin >> n;
		int c0 = NIL;
		rep(i, n){
			int c; cin >> c;
			if (i == 0){
				Nodes[p].left = c;
				Nodes[c].parent = p;
			}
			else{
				Nodes[c0].right = c;
				Nodes[c].parent = p;
			}
			c0 = c;
		}
	}

	// output
	rep(i, N){

		vint cren = children(i);
		cout << "node " << i << ": parent = " << Nodes[i].parent << ", depth = " << depth(i) << ", " << attr(i) << ", ";
		cout << "[";
		for (vint::iterator it = cren.begin(); it != cren.end(); it++){
			if (it != cren.begin()) cout << ", ";
			cout << *it;
		}
		cout << "]" << endl;
	}

}