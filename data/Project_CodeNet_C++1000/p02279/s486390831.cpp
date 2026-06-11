#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAX = 100005;
struct Node {
    int parent, left, right;
};
Node T[MAX];
int D[MAX];
void getDepth(int, int);
void printChild(int);
int main() {
    int t, id, k, temp, temp_1, head;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        T[i].parent = -1, T[i].left = -1, T[i].right = -1;
    }
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &id, &k);
        for(int j = 0; j < k; j++) {
            temp_1 = temp;
            scanf("%d", &temp);
            T[temp].parent = id;
            if(!j) T[id].left = temp;
            else T[temp_1].right = temp;
        }
    }
    for(int i = 0; i < t; i++) {
        if(T[i].parent == -1) head = i;
    }
    getDepth(head, 0);
    for(int i = 0; i < t; i++) {
        printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, D[i]);
        if(T[i].parent == -1) printf("root, [");
        else if(T[i].left == -1) printf("leaf, [");
        else printf("internal node, [");
        printChild(i);
    }
    return 0;
}
void getDepth(int u, int p) {
    D[u] = p;
    if(T[u].right != -1) getDepth(T[u].right, p);
    if(T[u].left != -1) getDepth(T[u].left, p+1);
}
void printChild(int u) {
    int c = T[u].left;
    int flag = 0;
    while(c != -1) {
        if(!flag) flag++;
        else printf(", ");
        printf("%d", c);
        c = T[c].right;
    }
    printf("]\n");
}

