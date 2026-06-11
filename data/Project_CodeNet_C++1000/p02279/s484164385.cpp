#include <iostream>
#include <vector>

constexpr int MAX_NUM = 100000;
struct Node{int p, l, r;};
Node T[MAX_NUM];
int D[MAX_NUM] = {};
int buf[MAX_NUM];

int getChild(int id, int* child_ary) {
    int n = 0;
    if (T[id].l == -1) return n;
    else {
        int c= T[id].l;
        while (c != -1) {
            child_ary[n++] = c;
            c = T[c].r;
        }
    }
    return n;
}

void printNode(int id) {
    std::string type;
    if (T[id].p == -1) {
        type = "root";
    }else{
        if (T[id].l != -1) type = "internal node";
        else type = "leaf";
    }
    int n = getChild(id, buf);
    std::printf("node %d: parent = %d, depth = %d, %s, ",
                id, T[id].p, D[id], type.c_str());
    std::printf("[");
    for (int i = 0; i < n; i++) {
        if(i) std::printf(", ");
        std::printf("%d", buf[i]);
    }
    std::printf("]\n");
}

void setDepth(int r, int d) {
    D[r] = d;
    if (T[r].l > -1) setDepth(T[r].l, d + 1);
    if (T[r].r > -1) setDepth(T[r].r, d);
}


int main(int argc, char** argv) {
    int Node = {};
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        T[i].l = -1;
        T[i].r = -1;
        T[i].p = -1;
    }
    for (int i = 0; i < n; i++) {
        int id, k, l, c;
        std::cin >> id >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> c;
            if (j == 0) T[id].l = c;
            else {
                T[l].r = c;
            }
            l = c;
            T[c].p = id;
        }
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (T[i].p == -1) {
            root = i;
        }
    }

    setDepth(root, 0);
    for (int i = 0; i < n; i++) {
        printNode(i);
    }
}

