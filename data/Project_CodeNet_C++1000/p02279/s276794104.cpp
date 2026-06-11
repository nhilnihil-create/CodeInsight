#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int NIL = -1;
int N;

// 自身のidは配列の要素数として管理する
struct Node {
	int parent; // 親
	int right; // 右の兄弟
	int left; // 左の子供
};

Node T[100000];
int D[100000];

void printChildren(int id) {
	cout << "[";

	int c = T[id].left;
	bool f = false;
	if (c != NIL) {
		cout << c;
		c = T[c].right;

		while (c != NIL) {
			cout << ", " << c;
			c = T[c].right;
		}
	}
	cout << "]";
}

void setDepth(int id, int d) {
	D[id] = d;

	if (T[id].right != NIL) {
		setDepth(T[id].right, d);
	}
	if (T[id].left != NIL) {
		setDepth(T[id].left, d + 1);
	}
}

string checkType(int id) {
	if (T[id].parent == NIL) return "root";
	else if (T[id].left == NIL) return "leaf";
	else return "internal node";
}

void print(int id) {
	cout << "node " << id << ": " << "parent = " << T[id].parent << ", depth = " << D[id]
		<< ", " << checkType(id) << ", ";

	printChildren(id);

	cout << endl;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		T[i].parent = NIL;
		T[i].right = NIL;
		T[i].left = NIL;
	}

	int id = NIL;
	int cnum;
	for (int j = 0; j < N; j++) {
		cin >> id >> cnum;


		// 子供のidを調べる
		vector<int> cId(cnum);
		for (int i = 0; i < cnum; i++) {
			cin >> cId[i];
		}

		// 子供の設定
		for (int i = 0; i < cnum; i++) {

			// これが一番左の子
			if (i == 0) {
				T[id].left = cId[i];
			}
			// 子供に右の子を設定する
			if (i < cnum - 1) {
				T[cId[i]].right = cId[i + 1];
			}

			// 親を設定
			T[cId[i]].parent = id;
		}

	}

	int r;
	for (int i = 0; i < N; i++) {
		if (T[i].parent == NIL) {
			r = i;
			break;
		}
	}

	// 深さを計算する
	setDepth(r, 0);

	for (int i = 0; i < N; i++) {
		print(i);
	}

	return 0;
}
