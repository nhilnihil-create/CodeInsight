#include<iostream>
using namespace std;
#define MAX 100000
#define NILL 0
struct Node {
	long long parent,node,key,left, right;
};
Node *T;
void print(int u) {
	cout << "node " << T[u].node << ": ";
	cout << "key = " << T[u].key << ", ";
	if(T[u].parent!=NILL)cout << "parent key = " << T[u].parent << ", ";
	if (T[u].left!=NILL)cout << "left key = " << T[u].left << ", ";
	if (T[u].right!=NILL)cout << "right key = " << T[u].right << ", ";
	cout << endl;
}

int main() {
	int n;
	long long id;
	cin >> n;
	T=new Node[n];
	for (int i = 0; i < n; i++){ 
		T[i].parent = T[i].left = T[i].right = NILL;
	}
    for (int i = 0; i < n; i++) {
		cin >> id;
		T[i].key = id;
		T[i].node = i+1;
    }
	for (int i = 0; i < n; i++) {
		T[i].left = T[2 * i + 1].key;
	    T[2 * i + 1].parent=T[i].key;
		T[i].right = T[2 * i + 2].key;
		T[2 * i + 2].parent = T[i].key;;
	}
	for (int i = 0; i < n; i++) {
		print(i);
	}
}
