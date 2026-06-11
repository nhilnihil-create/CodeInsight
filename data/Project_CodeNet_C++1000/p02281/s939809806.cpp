#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class node {
public:
	int parent,children[2],depth,height,sib;
	node() {
		parent = -1;
		children[0] = -1;
		children[1] = -1;
		depth = -1;
		height = -1;
		sib = -1;
	}
	int deg() {
		int c = 0;
		for(int i=0;i<2;i++)if(children[i]!=-1)c++;
		return c;
	}
	string typ() {
		if(parent == -1)return "root";
		else if(deg() == 0)return "leaf";
		else return "internal node";
	}
};

int n;
node d[100000];

void pre(int i) {
	cout << " " << i;
	if(d[i].children[0] != -1) pre(d[i].children[0]);
	if(d[i].children[1] != -1) pre(d[i].children[1]);
}

void ino(int i) {
	if(d[i].children[0] != -1)ino(d[i].children[0]);
	cout << " " << i;
	if(d[i].children[1] != -1)ino(d[i].children[1]);
}

void pos(int i) {
	if(d[i].children[0] != -1)pos(d[i].children[0]);
	if(d[i].children[1] != -1)pos(d[i].children[1]);
	cout << " " << i;
}

int main(void) {
	char * c = new char[1000*1000*100];
	cin >> n;
	for(int i = 0;i < n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		d[a].children[0] = b;
		d[a].children[1] = c;
		d[b].sib = c;
		d[c].sib = b;
		d[b].parent = a;
		d[c].parent = a;
	}
	int rt = -1;
	for(int i = 0;i < n;i++){
		if(d[i].parent == -1) {
			rt = i;
		}
	}
	d[rt].depth = 0;
	cout << "Preorder" << endl;
	pre(rt);
	cout << endl << "Inorder" << endl;
	ino(rt);
	cout << endl << "Postorder" << endl;
	pos(rt);
	cout << endl;
}

