#include<iostream>
using namespace std;

static const int NIL = -1;

int n;

struct Node {
	int p, l, r;
} T[30];

void preorder(int r) {
	cout << ' ' << r;
	if (T[r].l != NIL) preorder(T[r].l);
	if (T[r].r != NIL) preorder(T[r].r);
}

void inorder(int r) {
	if (T[r].l !=NIL) inorder(T[r].l);
	cout << ' ' << r;
	if (T[r].r !=NIL) inorder(T[r].r);
}

void postorder(int r) {
	if (T[r].l != NIL) postorder(T[r].l);
	if (T[r].r != NIL) postorder(T[r].r);
	cout << ' ' << r;
}

int main() {
	int r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		T[i].p = T[i].l = T[i].r = NIL; //?????????
	}

	for (int i = 0; i < n; i++) {
		int id, tl, tr;
		cin >> id >> tl >> tr;
		T[id].l = tl;
		T[id].r = tr;
		T[tl].p = T[tr].p = id;
	}

	for (int i = 0; i < n; i++) {
		if (T[i].p ==NIL) r = i;
	}
	
	cout << "Preorder" << endl;
	preorder(r);
	cout << endl;
	cout << "Inorder" << endl;
	inorder(r);
	cout << endl;
	cout << "Postorder" << endl;
	postorder(r);
	cout << endl;

	return 0;
}