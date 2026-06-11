#include<stdio.h>
#include<string>

#define MAX 100000

struct Node {
    int parent;
    int left;
    int right;
    int depth;
};

Node N[MAX];

void setDepth(Node& n, int depth) {
    Node* cur = &n;
    while (true) {
        cur->depth = depth;
        if (cur->left >= 0) {
            setDepth(N[cur->left], depth + 1);
        }
        if (cur->right < 0) break;
        cur = &N[cur->right];
    }
}

void print(Node n, int id) {
    std::string type;
    if (n.parent < 0) {
        type = "root";
    }
    else if (n.left < 0) {
        type = "leaf";
    }
    else {
        type = "internal node";
    }


    printf("node %d: parent = %d, depth = %d, %s, [", id, n.parent, n.depth, type.c_str());
    if (n.left >= 0) {
        printf("%d", n.left);
        Node cur = N[n.left];
        while (cur.right >= 0) {
            printf(", %d", cur.right);
            cur = N[cur.right];
        }
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        N[i].parent = -1;
        N[i].left = -1;
        N[i].right = -1;
    }

    for (int i = 0; i < n; ++i) {
        int id, k;
        scanf("%d", &id);
        scanf("%d", &k);

        if (k <= 0) continue;

        int left = -1;
        int C[k];
        for (int j = 0; j < k; ++j) {
            scanf("%d", &C[j]);
        }
        for (int j = 0; j < k; ++j) {
            N[C[j]].parent = id;
            N[C[j]].right = j < k-1 ? C[j+1] : -1;
        }
        N[id].left = C[0];
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (N[i].parent == -1) {
            root = i;
            break;
        }
    }

    setDepth(N[root], 0);

    for (int i = 0; i < n; ++i) print(N[i], i);

}