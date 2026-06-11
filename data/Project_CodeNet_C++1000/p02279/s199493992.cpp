#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define NIL -1
#define MAX 100001

struct Node {
    int parent, left, right;
};

vector<Node> t(MAX, {NIL, NIL, NIL});
vector<int> d(MAX);

void set_depth(int u, int p) {
    d[u] = p;
    if (t[u].right != NIL) {
        set_depth(t[u].right, p);
    }
    if (t[u].left != NIL) {
        set_depth(t[u].left, p+1);
    }
}

int get_depth(int u) {
    int p = 0, v = u;
    while (t[v].parent != NIL) {
        v = t[v].parent;
        p++;
    }
    return d[u] = p;
}

int main() {
    int n;
    scanf("%d", &n);
    rep(i, n) {
        int id, k;
        scanf("%d %d", &id, &k);
        int l;
        rep(j, k) {
            int c;
            scanf("%d", &c);
            t[c].parent = id;
            if (j == 0) t[id].left = c;
            else t[l].right = c;
            l = c;
        }
    }

    // int r;
    // rep(i, n) {
    //     if (t[i].parent == NIL) {
    //         r = i;
    //         break;
    //     }
    // }
    // set_depth(r, 0);
    
    rep(i, n) {
        printf("node %d: parent = %d, ", i, t[i].parent);
        // printf("depth = %d, ", d[i]);
        printf("depth = %d, ", get_depth(i));
        if (t[i].parent == NIL) printf("root");
        else if (t[i].left == NIL) printf("leaf");
        else printf("internal node");
        printf(", [");
        int u = t[i].left;
        if (u != NIL) {
            printf("%d", u);
            while (t[u].right != NIL) {
                printf(", %d", t[u].right);
                u = t[u].right;
            }
        }
        printf("]\n");
    }
}
