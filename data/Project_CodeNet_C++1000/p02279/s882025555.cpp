#include <iostream>
using namespace std;
#define Nil -1;

struct Node { int parent, left, right; };

int getDepth(Node* T,int u) {
	int d = 0;
	while(T[u].parent != -1){
		u = T[u].parent;
		d++;
	}
	return d;
}

void setDepth(Node* T,int u, int p,int* D) {
	D[u] = p;
	if (T[u].right != -1)
		setDepth(T, T[u].right, p,D);
	if (T[u].left != -1)
		setDepth(T, T[u].left, p+1, D);
}

void printfChildren(Node* T,int u) {
	int c = T[u].left;
	int i = 0;
	while (c != -1) {
		if (i++) cout << ", ";
		cout << c;
		c = T[c].right;
	}
}

int main(void) {

	int N = 0;

	cin >> N;
	struct Node* T = new Node[N];
	int* D = new int[N];
	int* n = new int[N];
	int* c = new int[N];

	for (int i = 0; i < N; i++) {
		T[i].parent = Nil; T[i].left = Nil; T[i].right = Nil;
		D[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> n[i] >> c[i];
		if (c[i] != 0) {
			cin >> T[n[i]].left;
			int u = T[n[i]].left;
			for (int j = 0; j < c[i]; j++) {
				T[u].parent = n[i];
				if (j == c[i] - 1) {
					T[u].right = Nil;
					break;
				}
				cin >> T[u].right;
				u = T[u].right;
			}
		}
		else
			T[n[i]].left = Nil;
	}

	int r = 0;
	for (int i = 0; i < N; i++) {
		if (T[i].parent == -1) r = i;
	}

	setDepth(T, r, 0, D);
	
	for (int i = 0; i < N; i++) {
		cout << "node " << i << ": parent = " << T[i].parent << ", depth = " << D[i];
		if (T[i].parent == -1)
			cout << ", root, [";
		else if (T[i].left == -1)
			cout << ", leaf, [";
		else
			cout << ", internal node, [";
		printfChildren(T, i);

		cout << "]\n";
	}
}
