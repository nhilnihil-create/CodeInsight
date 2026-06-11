#include<iostream>
using namespace std;
#define MAX 100001
#define NIL -1
struct Node {int p, l, r;};

Node T[MAX];
int n, D[MAX];

void print(int i) {
	cout << "node " << i << ": parent = " << T[i].p << ", ";
	cout << "depth = " << D[i] << ", ";
	
	//who are you?
	if (T[i].p == NIL) {
	cout << "root";
	}
	else if (T[i].l == NIL) {
	cout << "leaf";
	}
	else {
	cout << "internal node";
	}

	cout << ", [";

	for (int j = 0, k = T[i].l; k != NIL; j++, k = T[k].r) {
	if (j) cout << ", ";
	cout << k ;
	}
	
	cout << "]" << endl;
}

//?????°????????±??????map????????????
void make_d(int u, int p) {
	D[u] = p;
	if (T[u].l != NIL) {
	make_d(T[u].l, p+1);
	}
	if (T[u].r != NIL) {
	make_d(T[u].r, p);
	}
}

int main() {
	cin >> n;
	int par, child_sum, child;
	int left_for_next;
	//??????T??????????????????????????????
	for (int i=0;i<n;i++) {
	T[i].p = T[i].l = T[i].r = NIL;
	}

	for (int i=0;i<n;i++) {
	cin >> par >> child_sum;
	for (int j=0;j<child_sum;j++) {
	cin >> child;
	if (j==0) {
	T[par].l = child;
	}
	else {
	T[left_for_next].r = child;
	}
	//???????¨??????§??????????
	left_for_next = child;	//?¬????loop????????????????????????
	T[child].p = par;	
	}
	}
	int root;
	//root ??¢?????????
	for (int i=0;i<n;i++) {
	if (T[i].p == NIL) {
	root = i;
	break;
	}
	}

	make_d(root,0);

	for (int i=0;i<n;i++) {
	print(i);
 	}
	return 0;
}
	




 
	