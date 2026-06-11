#include <bits/stdc++.h>
using namespace std;
static const int MAX = 100000;
static const int NIL = -1;

class Node {
    public:
        int parent, left, right;
        Node();
        string type();
};
Node::Node() {
    parent = left = right = NIL;
}

Node T[MAX]; // 配列Tの添え字がid
int D[MAX]; // それぞれのidの深さ

string Node::type() {
    if (parent == NIL) return "root";
    else if (left == NIL) return "leaf";
    else return "internal node";
}


// 節点の深さ
void setDepth(int u, int p) { // uはroot
    D[u] = p;
    if (T[u].right != NIL) setDepth(T[u].right, p);
    if (T[u].left != NIL) setDepth(T[u].left, p + 1);
}

void printChildren(int u) {
    int i = 0;
    int c = T[u].left;
    cout << "[";
    while (c != NIL) {
        if (i++) cout << ", ";
        cout << c;
        c = T[c].right;
    }
    cout << "]";
}


int main() {
    int n, id, k, c;
    cin >> n;
    // 子要素に親要素としてid,右兄弟要素として次の入力値を設定; 親要素に左子要素のみ設定;
    for (int i = 0; i < n; i++) {
        cin >> id >> k;
        int tmp;
        for (int j = 0; j < k; j++) {
            cin >> c;
            if (j == 0) T[id].left = c;
            else T[tmp].right = c;
            tmp = c;
            T[c].parent = id;
        }
    }

    for (int i = 0; i < n; i++) {
        if (T[i].parent == NIL) {
            setDepth(i, 0);
            break;
        }
    }
    
    // 出力
    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << T[i].parent << ", ";
        cout << "depth = " << D[i] << ", ";
        cout << T[i].type() << ", ";
        printChildren(i);
        cout << endl;
    }

    return 0;
}
