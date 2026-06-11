#include <iostream>

using namespace std;

#define NIL -1
#define MAX 100005

struct Node {
    int parent = NIL;
    int left = NIL;
    int right = NIL;
};

Node T[MAX];

int getDepth(int u) {
    int d = 0;
    while (T[u].parent != NIL) {
        u = T[u].parent;
        ++d;
    }
    return d;
}

string getType(int u) {
    if (T[u].parent == NIL) {
        return "root";
    } else if (T[u].left == NIL) {
        return "leaf";
    } else {
        return "internal node";
    }
}

void printChildren(int u) {
    int c = T[u].left;
    if (c != NIL) {
        printf("%d", c);
        c = T[c].right;
    }
    while (c != NIL) {
        printf(", %d", c);
        c = T[c].right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int parentId;
        int k;
        scanf("%d", &parentId);
        scanf("%d", &k);
        int currerntChildId;
        int previousChildId;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &currerntChildId);
            if (j == 0) {
                T[parentId].left = currerntChildId;
            }
            T[currerntChildId].parent = parentId;
            if (j > 0) {
                T[previousChildId].right = currerntChildId;
            }
            previousChildId = currerntChildId;
        }
    }

    for (int u = 0; u < n; ++u) {
        int depth = getDepth(u);
        string type = getType(u);
        printf("node %d: parent = %d, depth = %d, %s, [", u, T[u].parent, depth, type.c_str());
        printChildren(u);
        printf("]\n");
    }

    return 0;
}