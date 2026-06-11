#include <iostream>
using namespace std;

const long MAX = 100001;
const long NIL = -1;

struct Node{
	long parent, leftChild, rightSibling;
};

struct Node T[MAX];
long n, Depth[MAX];

void print(long id){
	cout << "node " << id << ": ";
	cout << "parent = " << T[id].parent << ", ";
	cout << "depth = " << Depth[id] << ", ";

	if (T[id].parent == NIL) cout << "root, ";
	else if (T[id].leftChild == NIL) cout << "leaf, ";
	else cout << "internal node, ";

	cout << "[";

	for (long i = 0, c = T[id].leftChild; c != NIL; i++, c = T[c].rightSibling){
		if (i) cout << ", ";
		cout << c;
	}
	cout << "]" << endl;
}

long setDepth(long id, long parent){
	Depth[id] = parent;
	if (T[id].rightSibling != NIL) setDepth(T[id].rightSibling, parent);
	if (T[id].leftChild != NIL) setDepth(T[id].leftChild, parent + 1);
}

int main(){
	long degree, id, child, leftChild, rightSibling;
	cin >> n;
	for (long i = 0; i < n; i++){
		T[i].parent = T[i].leftChild = T[i].rightSibling = NIL;
	}
	for (long i = 0; i < n; i++){
		cin >> id >> degree;
		for (long j = 0; j < degree; j++){
			cin >> child;
			if (j == 0) T[id].leftChild = child;
			else T[leftChild].rightSibling = child;
			leftChild = child;
			T[child].parent = id; 
		}
	}
	for (long i = 0; i < n; i++){
		if (T[i].parent == NIL) rightSibling = i;
	}

	setDepth(rightSibling, 0);

	for (long i = 0; i < n; i++) print(i);

	return 0;
}